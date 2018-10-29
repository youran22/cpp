#pragma once
//#include "string.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstddef> // std::size_t
#include <fstream>

// https://blog.csdn.net/fengbingchun/article/details/62417284
// https://github.com/fengbingchun
/*
	typedef basic_string<char, char_traits<char>, allocator<char> >			string;
	typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >	wstring;
	typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t> >	u16string;
	typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t> >	u32string;
*/

#include <string>
#include <sstream>

namespace std {
template <typename T>
std::string to_string(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

double stod(std::string str)
{
	double Result;  
	stringstream Oss;  
	Oss<<str;  
	Oss>>Result;  
	return Result;
}

}

//template <typename T>
//T decltype(T)
//{
//	return T;
//}
 
int test_string_init(); 
int test_string_base(); 
int test_string_cctype(); 
static void SplitFilename(const std::string& str); 
int test_string_func(); 
int test_string_ifstream_to_string();

