#include "sortfunctions.h"

//�㷨��Ʒ���
//�������飬���������
void insertion_sort(int *a, int n)
{
	int i,j,key;
	for(j=1;j<n;j++){
		key=a[j];
		i = j-1;
		while( (i>=0)&&(a[i]>key) ){
			a[i+1]=a[i];
			//a[i]=key;//�˲����ࣻ
			i--;
		}
		a[i+1]=key;//����
	}
}

//���飬���ȣ�����Ԫ�����ͳ��ȣ��ȽϺ���
//��ĳЩ�������У�void*��ʵ����ҪǿתΪchar*���ܱ��룻
void insertionSort(void *a, int n, int size, int (*comp)(void  *, void *))
{
	int i,j;
	char *key = (char *)malloc(size);//void *key = (void *)malloc(size)
	for (j=1;j<n;j++)
	{
		//��Ϊvoid*���ͱ���ϵͳ������ֱ�Ӹ�ֵ����������Ҫ��memcpy��λ��string.h��
		memcpy(key, (char *)a+j*size, size);//key <- a[j]
		i=j-1;
		while( (i>=0) && (comp((char *)a+i*size, key)>0) )//ͬ��void*���ܱȽϣ���Ҫ����һ���ȽϺ��������бȽ�
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