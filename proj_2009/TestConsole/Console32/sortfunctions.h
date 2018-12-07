#ifndef _SORTFUNCTIONS_H_
#define _SORTFUNCTIONS_H_
#include <string>//strcmp
using namespace std;//strcmp using namespace std::string;//std::string不是namespace

void insertion_sort(int *a, int n);

//任意类型
void insertionSort(void *a, int n, int size, int (*comp)(void  *, void *));

int int_greater(void *x, void *y);

int int_less(void *x, void *y);
int char_greater(void *x, void *y);
int char_less(void *x, void *y);
int str_greater(void *x, void *y);
int str_less(void *x, void *y);

int float_greater(void *x, void *y);

#endif //_SORTFUNCTIONS_H_
