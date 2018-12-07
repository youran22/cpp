#include "t_boost_timer.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//参考：https://www.cnblogs.com/flyinggod/p/8324396.html

/*
步骤：
1、定义一个boost::asio::io_service;
2、根据boost::asio::io_service，创建一个boost::asio::deadline_timer；
3、async_wait 回调函数；
4、io.run();
*/
void time_print(const boost::system::error_code & /*e*/)
{
	std::cout << "Hello, world!";
}
void test_boost_timer()
{
	//io_service对象，它提供了IO调度功能，asio库中的所有io操作都是基于它来执行的。
	boost::asio::io_service io;
	//deadline_timer对象，它有两个参数，一个是io_service对象，另一个是超时时间
	boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));

	//同步方式 创建了timer后，就可以调用wait函数来阻塞等待至timer超时了，它还有一种可以指定错误码的入参的重载形式
	//timer.wait();

	//异步
	//	1、调用的是非阻塞函数async_wait，它的入参是一个回调函数。
	//	2、显式调用io_service.run()函数驱动异步IO调度。
	timer.async_wait(&time_print);//等待，如果时间到了，就调用函数；
	io.run();


	std::cout <<"Hello, world!";//5s之后调用；
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//取消timer
//Timer还有一种常用操作是取消Timer，基本方法如下：
//调用timer的cancel函数取消timer
//timer取消后，回调函数会立即执行，通过err_code可以感知到计时器是否已经被取消
void time_print_cncel(const boost::system::error_code& err)
{
	if(err)
	{
		std::cout << "timer is canceled\n";
		return;
	}

	std::cout << "Hello, world!\n";
}
int test_boost_timer_cancel()
{
	boost::asio::io_service io;

	boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
	timer.async_wait(&time_print_cncel);//等待5秒后，调用函数；

	boost::asio::deadline_timer timer2(io, boost::posix_time::seconds(5));
	timer2.wait();
	timer.cancel();

	io.run();//只有io驱动后才会执行等待操作？
	return 0;//只输出"timer is canceled\n" ? 没有打印Hello？？
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
更改Timer超时时间

	可以通过expires_from_now和expires_at两个函数更改Timer的超时时间，如下示例就通过它实现一个周期计时器。
*/
typedef std::function<void (const boost::system::error_code&)> timer_callback ;
void print(const boost::system::error_code&)
{
	std::cout << "Hello, world!\n";
}

int test_boost_timer_expires()
{
	boost::asio::io_service io;
	boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));

	//定义并实现定时器回调函数；
	timer_callback callback = [&](const boost::system::error_code& err) 
	{
		print(err);
		timer.expires_at(timer.expires_at() + boost::posix_time::seconds(1));
		timer.async_wait(callback);
	};

	timer.async_wait(callback);
	io.run();

	return 0;//第一次等待5秒，触发调用回调；之后每次都是1秒间隔回调；
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//#include <iostream>  
//#include <boost/asio.hpp>  
//#include <boost/bind.hpp>  
//#include <boost/date_time/posix_time/posix_time.hpp>  

class printer  
{  
public:  
	printer(/*boost::asio::io_service& io*/)  
		: timer_(io, boost::posix_time::seconds(1)),  
		count_(0)  
	{  
		//timer_.async_wait(boost::bind(&printer::print, this));  
	}  

	~printer()  
	{  
		std::cout << "Final count is " << count_ << "\n";  
	}  

	void print()  
	{  
		if (count_ < 5)  
		{  
			std::cout << count_ << "\n";  
			++count_;  

			//以当前时刻从新计算时间，间隔1秒后调用；
			timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));  
			timer_.async_wait(boost::bind(&printer::print, this));  
		}  
	}
	
	void Run()
	{
		timer_.async_wait(boost::bind(&printer::print, this)); 
		io.run();
	}

public:
	void start()
	{
		//boost::function0< void> f =  boost::bind(&printer::Run,this);
		//boost::thread thrd( f );
		//thrd.join();

	}

private:  
	boost::asio::deadline_timer timer_;  
	int count_; 
	boost::asio::io_service io;  
};  

int time_print_class()  
{  
	//boost::asio::io_service io;  
	//printer p(io);
	//io.run(); 

	printer p;
	p.start();

	return 0;//封装成类，如果<5则一直执行这个函数；  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <iostream>  
//#include <time.h>  
//#include <boost/asio.hpp>  
//#include <boost/bind.hpp>    
//#include <boost/function.hpp>  
//#include <boost/date_time/posix_time/posix_time.hpp>    
  
//using namespace std;  
  
//超时控制器类  
class TimerController   
{  
public:  
  
    /** 
     * 超时控制器构造函数 
     * @param ios 异步I/O对象 
     * @param callbackFunc 超时处理回调函数 
     * @param uiWaitSec 定时器间隔等待时间，单位：秒 
     */  
    explicit TimerController(boost::asio::io_service &ios, boost::function<void()> callbackFunc, unsigned int uiWaitSec) :  
            m_timer(ios, boost::posix_time::seconds(3))//一开始创建一个3s的定时器；   
    {  
        std::cout<< "1111111111111" << "-----" << time(NULL)<<"\n";  
        m_timeoutHandle = callbackFunc;  
        m_uiWaitSec = uiWaitSec;  
        m_timer.async_wait(boost::bind(&TimerController::onTime, this, boost::asio::placeholders::error));  
    }  
  
    /** 
     * 析构函数 
     */  
    ~TimerController()   
    {  
        m_timer.cancel();  
    }  
  
    /** 
     * 定时器响应函数 
     * @param error_code 定时器异常错误信息 
     */  
    void onTime(const boost::system::error_code&)//循环调用调用定时；
    {  
        m_timeoutHandle();  
        m_timer.expires_at(m_timer.expires_at() + boost::posix_time::seconds(m_uiWaitSec));  
        m_timer.async_wait(boost::bind(&TimerController::onTime, this, boost::asio::placeholders::error));  
    }  
  
private:  
    unsigned int                    m_uiWaitSec;                //定时间间隔等待时间  
    boost::asio::deadline_timer     m_timer;                    //asio定时器  
    boost::function<void()>           m_timeoutHandle;            //超时处理回调函数  
};  
  
  
//构造函数  
class CmdQueueManager  
{  
public:  
    CmdQueueManager(boost::asio::io_service* io)
    {
			//io, 回调函数，调用回调函数的时间间隔；
        m_pTimer     = new TimerController(*io,boost::bind(&CmdQueueManager::SendProcess, this),2);
    }  
      
    void SendProcess()  
    {  
        std::cout<< "111111" << "-----" << time(NULL)<<"\n";  
    }  
      
    TimerController *               m_pTimer;  
};  
  
int time_print_class_second()   
{  
    boost::asio::io_service io;  
      
    CmdQueueManager t(&io);
    io.run();  
      
    return 0;//  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CTimerController0
{
public:
	/** 
   * 超时控制器构造函数 
   * @param ios 异步I/O对象 
   * @param callbackFunc 超时处理回调函数 
   * @param uiWaitSec 定时器间隔等待时间，单位：秒 
   */ 
	explicit CTimerController0(boost::asio::io_service &ios, boost::function<void()> callbackFunc, unsigned int uiWaitSec)
		: m_timer(ios, boost::posix_time::seconds(3))
	{
		m_callbackfunc = callbackFunc;  
		m_uiWaitSec = uiWaitSec;  
		m_timer.async_wait(boost::bind(&CTimerController0::OnTimer, this, boost::asio::placeholders::error));
	}
	~CTimerController0(void)
	{
		m_timer.cancel();
	}
private:
	/*
	* 超时定时器响应函数
	* @param error_code 定时器异常错误信息
	*/
	void OnTimer(const boost::system::error_code&)
	{
		m_callbackfunc();
		m_timer.expires_at(m_timer.expires_at() + boost::posix_time::seconds(m_uiWaitSec));
		m_timer.async_wait(boost::bind(&CTimerController0::OnTimer, this, boost::asio::placeholders::error));
	}

private:
	unsigned int  m_uiWaitSec;//定时等待间隔
	boost::asio::deadline_timer m_timer;//asio定时器
	boost::function<void()>	m_callbackfunc;//超时处理回调函数
};

class CmdQueueManager2  
{  
public:  
	CmdQueueManager2(boost::asio::io_service* io)
	{
		//io, 回调函数，调用回调函数的时间间隔；
		m_pTimer     = new CTimerController0(*io,boost::bind(&CmdQueueManager2::SendProcess, this),2);
	}  
protected:
	void SendProcess()  
	{  
		std::cout<< "111111" << "-----" << time(NULL)<<"\n";  
	}  
protected:
	CTimerController0 *               m_pTimer;  
};

int time_print_class_third()
{
	boost::asio::io_service io;

	CmdQueueManager2 t(&io);
	io.run();

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////


//#include <vector>
//#include <thread>
//#include <atomic>
//#include <functional>
//#include <boost/timer.hpp>
//#include <boost/asio.hpp>

//template<typename Duration = boost::posix_time::milliseconds>
//class ATimer0
//{
//public:
//	ATimer0() : m_work(m_ios), m_timer(m_ios), m_isSingleShot(false) {}
//	~ATimer0()
//	{
//		destroy();
//	}
//
//	void start(std::size_t duration)
//	{
//		if (m_ios.stopped())
//		{
//			return;
//		}
//
//		m_duration = duration;
//		m_thread = std::thread([this]{ m_ios.run(); });
//		start();
//	}
//
//	void start()
//	{
//		m_timer.expires_from_now(Duration(m_duration));
//		m_timer.async_wait([this](const boost::system::error_code& ec)
//		{
//			if (ec)
//			{
//				return;
//			}
//
//			for (auto& func : m_funcVec)
//			{
//				func();
//			}
//
//			if (!m_isSingleShot)
//			{
//				start();
//			}
//		});
//	}
//
//	void stop()
//	{
//		m_timer.cancel();
//	}
//
//	void destroy()
//	{
//		stop();
//		m_ios.stop();
//		if (m_thread.joinable())
//		{
//			m_thread.join();
//		}
//	}
//
//	void bind(const std::function<void()>& func)
//	{
//		m_funcVec.emplace_back(func);
//	}
//
//	void setSingleShot(bool isSingleShot)
//	{
//		m_isSingleShot = isSingleShot; 
//	}
//
//private:
//	boost::asio::io_service m_ios;
//	boost::asio::io_service::work m_work;
//	boost::asio::deadline_timer m_timer;
//	std::function<void()> m_func;
//	std::vector<std::function<void()>> m_funcVec;
//	std::thread m_thread;
//	std::size_t m_duration;
//	std::atomic<bool> m_isSingleShot;
//};

template<typename Duration = boost::posix_time::milliseconds>
class ATimer
{
public:
	ATimer() : m_timer(m_ios, Duration(0)), m_isSingleShot(false) {
		m_func = 0;
		m_duration = 0;
		m_isSingleShot = false;
	}
	~ATimer()
	{
		stop();
	}

	void start(unsigned int duration)
	{
		if (m_ios.stopped())
		{
			return;
		}

		m_isActive = true;
		m_duration = duration;
		m_timer.expires_at(m_timer.expires_at() + Duration(m_duration));

		m_func = [this]
		{
			m_timer.async_wait([this](const boost::system::error_code&)
			{
				for (auto& func : m_funcVec)
				{
					func();
				}

				if (!m_isSingleShot)
				{
					m_timer.expires_at(m_timer.expires_at() + Duration(m_duration));
					m_func();
				}
			});
		};

		m_func();
		m_thread = std::thread([this]{ m_ios.run(); });
	}

	void stop()
	{
		m_ios.stop();
		if (m_thread.joinable())
		{
			m_thread.join();
		}
		m_isActive = false;
	}

	void bind(const std::function<void()>& func)
	{
		m_funcVec.emplace_back(func);
	}

	void setSingleShot(bool isSingleShot)
	{
		m_isSingleShot = isSingleShot; 
	}

	bool isSingleShot() const
	{
		return m_isSingleShot;
	}

	bool isActive() const
	{
		return m_isActive;
	}

private:
	boost::asio::io_service m_ios;
	boost::asio::deadline_timer m_timer;
	std::function<void()> m_func;
	std::vector<std::function<void()>> m_funcVec;
	std::thread m_thread;
	unsigned int m_duration ;
	std::atomic<bool> m_isSingleShot;
	bool m_isActive ;
};

void test()
{
	std::cout << "Timer thread id: " << std::this_thread::get_id() << std::endl;
}

int time_print_class_four()
{
	//std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;

	//ATimer<> t0;
	//t0.setSingleShot(true);// 单次调用
	//t0.bind(test);
	//t0.start(1);// 一分钟之后调用

	//ATimer<> t;//默认使用毫秒定时器
	//t.bind(test);
	//t.bind([]{ std::cout << "Hello C++" << std::endl; });
	//t.start(1000);//每1000ms调用一次

	//std::cin.get();
	//t0.stop();
	//t.stop();
	//std::cout << "Tiemr stop" << std::endl;

	//std::cin.get();
	//std::cout << "Process end" << std::endl;
	return 0;
}//https://www.cnblogs.com/highway-9/p/5737421.html

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CTimerController
{
public:
	/** 
   * 超时控制器构造函数 
   * @param ios 异步I/O对象 
   * @param callbackFunc 超时处理回调函数 
   * @param uiWaitSec 定时器间隔等待时间，单位：秒 
   */ 
	CTimerController(boost::function<void()> callbackFunc, unsigned int uiWaitSec)
		: m_timer(m_timer_io, boost::posix_time::seconds(3))
	{
		m_isActive = false;
		m_callbackfunc = callbackFunc;  
		m_uiWaitSec = uiWaitSec;		
	}
	~CTimerController(void)
	{
		m_timer.cancel();
	}
private:
	/*
	* 超时定时器响应函数
	* @param error_code 定时器异常错误信息
	*/
	void OnTimer(const boost::system::error_code&)
	{
		m_callbackfunc();  
		m_timer.expires_at(m_timer.expires_at() + boost::posix_time::seconds(m_uiWaitSec));  
		m_timer.async_wait(boost::bind(&CTimerController::OnTimer, this, boost::asio::placeholders::error));
	}
public:
	void start()
	{
		//if(m_timer_io->stopped())
		//{
		//	return;
		//}

		m_isActive = true;

		{
			m_timer.async_wait(boost::bind(&CTimerController::OnTimer, this, boost::asio::placeholders::error));

			boost::function0< void> f =  boost::bind(&CTimerController::io_run_begin,this);
			boost::thread thread1(f);
			thread1.join();

			//thrd = boost::thread(boost::bind(&boost::asio::io_service::run, &m_timer_io));

			//m_timer.async_wait(boost::bind(&CTimerController::OnTimer, this, boost::asio::placeholders::error));

			//m_timer_io.run();			
		}		
	}
private:
	void io_run_begin()
	{
		m_timer.async_wait(boost::bind(&CTimerController::OnTimer, this, boost::asio::placeholders::error));
		m_timer_io.run();
	}

public:
	boost::asio::io_service m_timer_io;
	//boost::asio::io_service  m_io;
private:
	unsigned int  m_uiWaitSec;//定时等待间隔
	boost::asio::deadline_timer m_timer;//asio定时器
	boost::function<void()>	m_callbackfunc;//超时处理回调函数
	bool m_isActive;
	boost::thread  thrd;

};

class CmdQueueManager3  
{  
public:  
	CmdQueueManager3(/*boost::asio::io_service* io*/)
	{
		//io, 回调函数，调用回调函数的时间间隔；
		boost::asio::io_service *io = new boost::asio::io_service();
		m_pTimer     = new CTimerController(/**io,*/boost::bind(&CmdQueueManager3::SendProcess, this),2);
		m_pTimer->start();
	}  
protected:
	void SendProcess()  
	{  
		std::cout<< "111111" << "-----" << time(NULL)<<"\n";  
	}  
protected:
	CTimerController *               m_pTimer;
};


int time_print_class_five()
{	
	CmdQueueManager3 t(/*&io*/);
	while(1);
	return 0;
	
}

/////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <string>
//#include <boost/asio.hpp>
//#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/asio/steady_timer.hpp>
//#include <boost/asio/placeholders.hpp>
//#include <functional>
//#include <ctime>
//#include <chrono>
//using namespace std;
//using namespace std::chrono;
//using namespace boost::posix_time;
//using namespace boost::gregorian;
//using namespace std::placeholders;

typedef function<void(int, time_t)> time_func_type;

class ExcuteTimer
{
public:
	ExcuteTimer(boost::asio::io_service &io):m_timer(io){}
	~ExcuteTimer(){ m_timer.cancel();}

	time_t local_now_tm()
	{
		return time(0);
	}

	char* time_t2str(time_t timestamp, char* timestr, int len)
	{
		struct tm *ptm;
		ptm = localtime(&timestamp);
		strftime(timestr, len, "%Y-%m-%d %H:%M:%S", ptm);
		cout << timestr << endl;
		return timestr;
	}

	time_t str2time_t(const char *timestr)
	{
		struct tm ptm;
		strptime(timestr, "%Y-%m-%d %H:%M:%S", &ptm);
		time_t t = mktime(&ptm);
		return t;
	}

	void runAt(time_t timestamp, time_func_type callback)
	{
		int seconds = timestamp - time(0);
		if(seconds <0) return;
		m_timer.expires_at(chrono::steady_clock::now() + chrono::seconds(seconds));
		m_timer.async_wait(std::bind(callback, 1, timestamp));
	}
	void runAt(std::string date, time_func_type callback)
	{
		time_t t = str2time_t(date.c_str());
		time_t now = time(0);
		if(t < now)
			return;
		int seconds = t-now;
		m_timer.expires_from_now(chrono::seconds(seconds));
		m_timer.async_wait(std::bind(callback, 2, t));
	}
	void runAfter(int seconds, time_func_type callback)
	{
		m_timer.expires_from_now(std::chrono::seconds(seconds));
		m_timer.async_wait(std::bind(callback, 3, time(0)+seconds));
	}

	void runCircle(int seconds, time_func_type callback)
	{
		cout << "circle" << endl;
		callback(1, time(0));
		m_timer.expires_from_now(std::chrono::seconds(seconds));
		m_timer.async_wait(std::bind(&ExcuteTimer::runCircle, this, seconds,callback));
	}
private:
	boost::asio::steady_timer m_timer;
};


void testPrint(int id, time_t tm)
{
	cout << "id==="<<id <<endl;
	cout << "tm==" << tm <<endl;
}

class TestF
{
public:
	TestF(){}
	~TestF(){}
	void print(int id)
	{
		cout << "id==="<< id << endl;
		cout << "test f" << endl;
		cout << "now:"<< time(0) << endl;
	}

};

class ExcuteTimerManager
{
public:
	ExcuteTimerManager():m_io(),m_work(m_io){}

	boost::asio::io_service& get_io()
	{
		return m_io;
	}
	void stop()
	{
		m_work.~work();
		m_io.stop();
	}
	void run()
	{
		m_io.run();
	}
private:
	boost::asio::io_service m_io;
	boost::asio::io_service::work m_work;
};

std::unique_ptr<ExcuteTimerManager> g_excuteTimerManager;

int time_print_class_six()
{
	g_excuteTimerManager.reset(new ExcuteTimerManager());
	boost::asio::io_service& io = g_excuteTimerManager->get_io();
	ExcuteTimer timer(io);
	ExcuteTimer timer2(io);
	ExcuteTimer timer3(io);
	TestF testf;
	//time_func_type func = std::bind(&TestF::print, &testf, _1);//error C2872: “_1”: 不明确的符号
	time_func_type func = std::bind(&TestF::print, &testf, std::placeholders::_1);
	// timer.runAt(time(0)+10, func);
	// timer2.runAt(time(0), func);
	timer3.runCircle(5, func);
	//timer.runAt(time(0)+5, testPrint);
	//timer.runAt(std::string("2019-1-1 10:20:00"), testPrint);
	//timer.runAfter(10, func);
	g_excuteTimerManager->run();

	while(1);
	return 0;
}

//g++ timer.cpp --std=c++11 -pthread -lboost_system -lboost_date_time
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/*
struct tm tt0={0};
//!!!特别注意，tt0最好赋初值，否则某些量容易出错 
//直接赋值tt0结构体，以下通过故意赋错的值实现天数的赋值 
//理论上如果赋天数应该是tt0.yday=234就行，但查阅文档后发现该值一般忽略，是由年月日确定后自动算出 
//因此网上采取这种方法，将月份赋值为0表示January，当天数tm_mday大于31的时候会自动调整。 
//[原文出处](http://stackoverflow.com/questions/9575131/why-is-mktime-changing-the-year-day-of-my-tm-struct) 
tt0.tm_sec = 0; 
tt0.tm_min = 0; 
tt0.tm_hour = 16; 
tt0.tm_mday = 234; 
tt0.tm_mon = 0; 
tt0.tm_year = 2015-1900;
//！！！特别注意：必须减1900,否则mktime报错 
time_t t0 = mktime(&tt0);

*/

//#include <ctype.h>
//#include <string.h>
//#include <time.h>
 
 
/*
 * We do not implement alternate representations. However, we always
 * check whether a given modifier is allowed for a certain conversion.
 */
#define ALT_E          0x01
#define ALT_O          0x02
//#define LEGAL_ALT(x)       { if (alt_format & ~(x)) return (0); }
#define LEGAL_ALT(x)       { ; }
#define TM_YEAR_BASE   (1970)
 
static   int conv_num(const char **, int *, int, int);
static int strncasecmp(char *s1, char *s2, size_t n);
 
static const char *day[7] = {
     "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
     "Friday", "Saturday"
};
static const char *abday[7] = {
     "Sun","Mon","Tue","Wed","Thu","Fri","Sat"
};
static const char *mon[12] = {
     "January", "February", "March", "April", "May", "June", "July",
     "August", "September", "October", "November", "December"
};
static const char *abmon[12] = {
     "Jan", "Feb", "Mar", "Apr", "May", "Jun",
     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
static const char *am_pm[2] = {
     "AM", "PM"
};
 
 
char * strptime(const char *buf, const char *fmt, struct tm *tm)
{
     char c;
     const char *bp;
     size_t len = 0;
     int alt_format, i, split_year = 0;
 
     bp = buf;
 
     while ((c = *fmt) != '/0') {
         /* Clear `alternate' modifier prior to new conversion. */
         alt_format = 0;
 
         /* Eat up white-space. */
         if (isspace(c)) {
              while (isspace(*bp))
                   bp++;
 
              fmt++;
              continue;
         }
                  
         if ((c = *fmt++) != '%')
              goto literal;
 
 
again:        switch (c = *fmt++) {
         case '%': /* "%%" is converted to "%". */
literal:
              if (c != *bp++)
                   return (0);
              break;
 
         /*
          * "Alternative" modifiers. Just set the appropriate flag
          * and start over again.
          */
         case 'E': /* "%E?" alternative conversion modifier. */
              LEGAL_ALT(0);
              alt_format |= ALT_E;
              goto again;
 
         case 'O': /* "%O?" alternative conversion modifier. */
              LEGAL_ALT(0);
              alt_format |= ALT_O;
              goto again;
             
         /*
          * "Complex" conversion rules, implemented through recursion.
          */
         case 'c': /* Date and time, using the locale's format. */
              LEGAL_ALT(ALT_E);
              if (!(bp = strptime(bp, "%x %X", tm)))
                   return (0);
              break;
 
         case 'D': /* The date as "%m/%d/%y". */
              LEGAL_ALT(0);
              if (!(bp = strptime(bp, "%m/%d/%y", tm)))
                   return (0);
              break;
 
         case 'R': /* The time as "%H:%M". */
              LEGAL_ALT(0);
              if (!(bp = strptime(bp, "%H:%M", tm)))
                   return (0);
              break;
 
         case 'r': /* The time in 12-hour clock representation. */
              LEGAL_ALT(0);
              if (!(bp = strptime(bp, "%I:%M:%S %p", tm)))
                   return (0);
              break;
 
         case 'T': /* The time as "%H:%M:%S". */
              LEGAL_ALT(0);
              if (!(bp = strptime(bp, "%H:%M:%S", tm)))
                   return (0);
              break;
 
         case 'X': /* The time, using the locale's format. */
              LEGAL_ALT(ALT_E);
              if (!(bp = strptime(bp, "%H:%M:%S", tm)))
                   return (0);
              break;
 
         case 'x': /* The date, using the locale's format. */
              LEGAL_ALT(ALT_E);
              if (!(bp = strptime(bp, "%m/%d/%y", tm)))
                   return (0);
              break;
 
         /*
          * "Elementary" conversion rules.
          */
         case 'A': /* The day of week, using the locale's form. */
         case 'a':
              LEGAL_ALT(0);
              for (i = 0; i < 7; i++) {
                   /* Full name. */
                   len = strlen(day[i]);
                   if (strncasecmp((char *)(day[i]), (char *)bp, len) == 0)
                       break;
 
                   /* Abbreviated name. */
                   len = strlen(abday[i]);
                   if (strncasecmp((char *)(abday[i]), (char *)bp, len) == 0)
                       break;
              }
 
              /* Nothing matched. */
              if (i == 7)
                   return (0);
 
              tm->tm_wday = i;
              bp += len;
              break;
 
         case 'B': /* The month, using the locale's form. */
         case 'b':
         case 'h':
              LEGAL_ALT(0);
              for (i = 0; i < 12; i++) {
                   /* Full name. */
                   len = strlen(mon[i]);
                   if (strncasecmp((char *)(mon[i]), (char *)bp, len) == 0)
                       break;
 
                   /* Abbreviated name. */
                   len = strlen(abmon[i]);
                   if (strncasecmp((char *)(abmon[i]),(char *) bp, len) == 0)
                       break;
              }
 
              /* Nothing matched. */
              if (i == 12)
                   return (0);
 
              tm->tm_mon = i;
              bp += len;
              break;
 
         case 'C': /* The century number. */
              LEGAL_ALT(ALT_E);
              if (!(conv_num(&bp, &i, 0, 99)))
                   return (0);
 
              if (split_year) {
                   tm->tm_year = (tm->tm_year % 100) + (i * 100);
              } else {
                   tm->tm_year = i * 100;
                   split_year = 1;
              }
              break;
 
         case 'd': /* The day of month. */
         case 'e':
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &tm->tm_mday, 1, 31)))
                   return (0);
              break;
 
         case 'k': /* The hour (24-hour clock representation). */
              LEGAL_ALT(0);
              /* FALLTHROUGH */
         case 'H':
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &tm->tm_hour, 0, 23)))
                   return (0);
              break;
 
         case 'l': /* The hour (12-hour clock representation). */
              LEGAL_ALT(0);
              /* FALLTHROUGH */
         case 'I':
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &tm->tm_hour, 1, 12)))
                   return (0);
              if (tm->tm_hour == 12)
                   tm->tm_hour = 0;
              break;
 
         case 'j': /* The day of year. */
              LEGAL_ALT(0);
              if (!(conv_num(&bp, &i, 1, 366)))
                   return (0);
              tm->tm_yday = i - 1;
              break;
 
          case 'M': /* The minute. */
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &tm->tm_min, 0, 59)))
                   return (0);
              break;
 
         case 'm': /* The month. */
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &i, 1, 12)))
                   return (0);
              tm->tm_mon = i - 1;
              break;
 
//       case 'p': /* The locale's equivalent of AM/PM. */
//            LEGAL_ALT(0);
//            /* AM? */
//            if (strcasecmp(am_pm[0], bp) == 0) {
//                 if (tm->tm_hour > 11)
//                     return (0);
//
//                 bp += strlen(am_pm[0]);
//                 break;
//            }
//            /* PM? */
//            else if (strcasecmp(am_pm[1], bp) == 0) {
//                 if (tm->tm_hour > 11)
//                     return (0);
//
//                 tm->tm_hour += 12;
//                 bp += strlen(am_pm[1]);
//                 break;
//            }
//
//            /* Nothing matched. */
//            return (0);
 
         case 'S': /* The seconds. */
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &tm->tm_sec, 0, 61)))
                   return (0);
              break;
 
         case 'U': /* The week of year, beginning on sunday. */
         case 'W': /* The week of year, beginning on monday. */
              LEGAL_ALT(ALT_O);
              /*
               * XXX This is bogus, as we can not assume any valid
               * information present in the tm structure at this
               * point to calculate a real value, so just check the
               * range for now.
               */
               if (!(conv_num(&bp, &i, 0, 53)))
                   return (0);
               break;
 
         case 'w': /* The day of week, beginning on sunday. */
              LEGAL_ALT(ALT_O);
              if (!(conv_num(&bp, &tm->tm_wday, 0, 6)))
                   return (0);
              break;
 
         case 'Y': /* The year. */
              LEGAL_ALT(ALT_E);
              if (!(conv_num(&bp, &i, 0, 9999)))
                   return (0);
 
              tm->tm_year = i - TM_YEAR_BASE;
              break;
 
         case 'y': /* The year within 100 years of the epoch. */
              LEGAL_ALT(ALT_E | ALT_O);
              if (!(conv_num(&bp, &i, 0, 99)))
                   return (0);
 
              if (split_year) {
                   tm->tm_year = ((tm->tm_year / 100) * 100) + i;
                   break;
              }
              split_year = 1;
              if (i <= 68)
                   tm->tm_year = i + 2000 - TM_YEAR_BASE;
              else
                   tm->tm_year = i + 1900 - TM_YEAR_BASE;
              break;
 
         /*
          * Miscellaneous conversions.
          */
         case 'n': /* Any kind of white-space. */
         case 't':
              LEGAL_ALT(0);
              while (isspace(*bp))
                   bp++;
              break;
 
 
         default: /* Unknown/unsupported conversion. */
              return (0);
         }
 
 
     }
 
     /* LINTED functional specification */
     return ((char *)bp);
}
 
 
static int conv_num(const char **buf, int *dest, int llim, int ulim)
{
     int result = 0;
 
     /* The limit also determines the number of valid digits. */
     int rulim = ulim;
 
     if (**buf < '0' || **buf > '9')
         return (0);
 
     do {
         result *= 10;
         result += *(*buf)++ - '0';
         rulim /= 10;
     } while ((result * 10 <= ulim) && rulim && **buf >= '0' && **buf <= '9');
 
     if (result < llim || result > ulim)
         return (0);
 
     *dest = result;
     return (1);
}
 
int strncasecmp(char *s1, char *s2, size_t n)
{
 if (n == 0)
    return 0;
 
 while (n-- != 0 && tolower(*s1) == tolower(*s2))
    {
      if (n == 0 || *s1 == '/0' || *s2 == '/0')
     break;
      s1++;
      s2++;
    }
 
 return tolower(*(unsigned char *) s1) - tolower(*(unsigned char *) s2);
}
//测试
//#include <conio.h>
//void main()
//{
//     struct tm newtime;
//     memset(&newtime,0x00,sizeof(struct tm));
// 
//     strptime("Tue, 27 Nov 2007 05:35:53","%a, %d %b %Y %H:%M:%S",&newtime);
////       strptime("03/10/2004 15:54:19","%d/%m/%Y %H:%M:%S",&newtime);
// 
//     getch();
// 
//}



bool _Base64Encode(const std::string& input, std::string* output)
{
	typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<string::const_iterator, 6, 8> > Base64EncodeIterator;
	stringstream result;
	copy(Base64EncodeIterator(input.begin()) , Base64EncodeIterator(input.end()), ostream_iterator<char>(result));
	size_t equal_count = (3 - input.length() % 3) % 3;
	for (size_t i = 0; i < equal_count; i++) {
		result.put('=');
	}
	*output = result.str();
	return output->empty() == false;	
}
bool _Base64Decode(const std::string& input, std::string* output)
{
	typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<string::const_iterator>, 8, 6> Base64DecodeIterator;
	stringstream result;
	try {
		copy(Base64DecodeIterator(input.begin()) , Base64DecodeIterator(input.end()), ostream_iterator<char>(result));
	} catch(...) {
		return false;
	}
	*output = result.str();
	return output->empty() == false;	
}

int base64_test()
{
	cout<<"    Base64系列第三篇C/C++中使用Base64编码解码(使用boost库)"<<endl;
	cout<<"  -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --"<<endl;
	cout<<" - http://blog.csdn.net/morewindows/article/details/11922519 -"<<endl;

	string input_str("MoreWindows - http://blog.csdn.net/morewindows?viewmode=contents ~!@#$%\r\n");
	string base64_str, output_str;

	cout<<"origin text: \n"<<input_str<<endl;

	_Base64Encode(input_str, &base64_str);
	cout<<"encode: \n"<<base64_str<<endl;

	_Base64Decode(base64_str, &output_str);
	cout<<"decode: \n"<<output_str<<endl;

	input_str="0000:1234";
	cout<<"input_str: "<<input_str<<endl;
	_Base64Encode(input_str, &base64_str);//MDAwMDoxMjM0
	cout<<"encode: "<<base64_str <<endl;
	_Base64Decode(base64_str, &output_str);
	cout<<"decode: "<<output_str<<endl;

	input_str="0000:1234";
	cout<<"input_str: "<<input_str<<endl;
	Base64::Encode(input_str, &output_str);
	cout<<"encode: "<<base64_str <<endl;
	Base64::Encode(base64_str, &output_str);
	cout<<"decode: "<<output_str<<endl;

	return 0;
}
