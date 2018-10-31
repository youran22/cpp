#include "../stdafx.h"
#include "file_test.h"
#include <fstream>
#include <string>


int file_open_test()
{
	std::string path="F:\\git_cpp\\proj_2009\\TestConsole\\Debug\\file_test.txt";
	std::string data="0x2c 0x0d 0x0a";

	std::ofstream myFile;
	myFile.open(path.c_str(), std::ios::app);
	myFile.write(data.c_str(), data.size());
	myFile << std::endl;
	myFile.close();
	return 0;
}