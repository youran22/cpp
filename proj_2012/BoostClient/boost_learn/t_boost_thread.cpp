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
//(2)���Ҫ��start()��hello()���������Ǿ�̬�������������ķ��������̣߳� 
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
//�����ַ�ʽ�������ڲ������̣߳�
////////////////////////////////////////////////////////////////////////////////
//�����ַ����������ڲ����������ⲿ�����̣߳� 
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