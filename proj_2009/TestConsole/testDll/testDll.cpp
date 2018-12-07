#include <iostream>
using namespace std;//为什么要用这个才能用cout？
#include "crc_functions.h"
int main()
{
	int a=3;
	int b=4;
	cout<<calculate_add(a,b)<<endl;
	while(1);
}