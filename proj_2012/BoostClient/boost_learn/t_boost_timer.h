#pragma once
//#include "SouthgnssTestBoss.h"
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <iostream>
#include <thread>
#include <atomic>
#include <boost/thread/thread.hpp>

void test_boost_timer();
int test_boost_timer_cancel();
int test_boost_timer_expires();
int time_print_class();
int time_print_class_second();
int time_print_class_third();
int time_print_class_four();
int time_print_class_five();

//#include <iostream>
#include <string>
//#include <boost/asio.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/placeholders.hpp>
#include <functional>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std::placeholders;

#include <ctype.h>
#include <string.h>
#include <time.h>
int time_print_class_six();
char * strptime(const char *buf, const char *fmt, struct tm *tm);

//https://github.com/SonnyRajagopalan/TimerAndCallback/blob/master/test/timerPoolTest.cpp



#include "../common/base64.h"
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
//#include <string>
//#include <iostream>
#include <sstream>
bool _Base64Encode(const std::string& input, std::string* output);
bool _Base64Decode(const std::string& input, std::string* output);
int base64_test();






















 
 
