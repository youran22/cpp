#include "sortfunctions.h"

//算法设计分析
//整形数组，数组个数；
void insertion_sort(int *a, int n)
{
	int i,j,key;
	for(j=1;j<n;j++){
		key=a[j];
		i = j-1;
		while( (i>=0)&&(a[i]>key) ){
			a[i+1]=a[i];
			//a[i]=key;//此步多余；
			i--;
		}
		a[i+1]=key;//？？
	}
}

//数组，长度，数组元素类型长度，比较函数
//在某些编译器中，void*的实参需要强转为char*才能编译；
void insertionSort(void *a, int n, int size, int (*comp)(void  *, void *))
{
	int i,j;
	char *key = (char *)malloc(size);//void *key = (void *)malloc(size)
	for (j=1;j<n;j++)
	{
		//因为void*类型变量系统不允许直接赋值操作，所以要用memcpy（位于string.h）
		memcpy(key, (char *)a+j*size, size);//key <- a[j]
		i=j-1;
		while( (i>=0) && (comp((char *)a+i*size, key)>0) )//同样void*不能比较，需要定义一个比较函数来进行比较
		{
			memcpy((char *)a+(i+1)*size, (char *)a+i*size, size);//a[i+1] <- a[i];
			i--;//i <- i-1
		}
		memcpy((char *)a+(i+1)*size, key, size);//a[i+1] <- key
	}
}

int int_greater(void *x, void *y)
{
	return ( *( (int*)x ) )-( *( (int*)y ) );
}

int int_less(void *x, void *y)
{
	return int_greater(y, x);
}

int char_greater(void *x, void *y)
{
	return ( *( (char*)x ) ) - ( *( (char*)y ) );
}

int char_less(void *x, void *y)
{
	return char_greater(y, x);
}

int str_greater(void *x, void *y)
{
	return strcmp( *( (char**)x ), *( (char**)y ) );
}

int str_less(void *x, void *y)
{
	return str_greater(y,x);
}

int float_greater(void *x, void *y)
{
	if( (*((float*)x) - *((float*)y)) > 0.0)
		return 1;
	if( (*((float*)x) - *((float*)y)) < 0.0)
		return -1;
	return 0;
}