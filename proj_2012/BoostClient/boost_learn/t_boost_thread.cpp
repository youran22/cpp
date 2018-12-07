#include "t_boost_thread.h"
void hello()
{
	while(1)
	{
		std::cout <<"Hello world, I'm a thread!"<< std::endl;
	}
	
}
int thread_1()
{
	boost::thread thrd(&hello);
	thrd.join();
	//while(1);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//(2)如果要求start()和hello()方法不能是静态方法则采用下面的方法创建线程： 
class HelloWorld
{
public:
	void hello()
	{
		while(1)
		{
			std::cout <<
				"Hello world, I''m a thread!"
				<< std::endl;
		}		
	}
	void start()
	{
		boost::function0< void> f =  boost::bind(&HelloWorld::hello,this);
		boost::thread thrd( f );
		thrd.join();
	}

}; 
int thread_2()
{
	HelloWorld hello;
	hello.start();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//第三种方式：在类内部创建线程；
////////////////////////////////////////////////////////////////////////////////
//第四种方法：用类内部函数在类外部创建线程； 
//class HelloWorld
//{
//public:
//	void hello(const std::string& str)
//	{
//		std::cout < }
//}; 
//
//int main(int argc, char* argv[])
//{ 
//	HelloWorld obj;
//	boost::thread thrd( boost::bind(&HelloWorld::hello,&obj,"Hello 
//		world, I''m a thread!" ) ) ;
//		thrd.join();
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////