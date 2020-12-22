#include "myisort.h"

void insertion_sort(int* arr, int len)
{
	int cnt;
	for (int i = 1; i < len; ++i)
	{
		if (*(arr+i) < *(arr+i-1))
		{
			cnt = 1;
			for (int j = 2; j <= i; ++j)
			{
				if (*(arr+i) >= *(arr+i-j))
				{
					break;
				}
				cnt++;
			}
			switch_elements(arr+i, cnt);
		}
	}
}

// i >= 1 , arr+i is avalible
void shift_element(int* arr, int i) 
{
	for (int j = i; j > 0; --j)
	{
		*(arr+j) = *(arr+j-1);
	}
}

void switch_elements(int* arr, int amount)
{
	int tmp = *arr;
	shift_element(arr-amount, amount);
	*(arr-amount) = tmp;
}

void print_array(int* arr, int len)
{
	printf("%d", *arr);
	for (int i = 1; i < len; ++i)
	{
		printf(",%d", *(arr+i));
	}
	printf("\n");
}