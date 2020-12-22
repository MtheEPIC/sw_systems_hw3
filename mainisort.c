#include <stdio.h>
#include "myisort.h"

#define ARRAY_SIZE 5

int main() 
{	
	int len = ARRAY_SIZE;
	int arr[ARRAY_SIZE];

	// fill array
	for (int i = 0; i < len; ++i)
	{
		scanf("%d", arr+i);
	}
	// sort array 
	insertion_sort(arr, len);
	// print sorted array
	print_array(arr, len);

	return 0;
}