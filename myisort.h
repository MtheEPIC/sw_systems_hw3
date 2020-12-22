#include <stdio.h>

// main funcs
void insertion_sort(int* arr, int len); //sort the given array
void shift_element(int* arr, int i); //shift all array pointer from a given point

// helper funcs
void switch_elements(int* arr, int amount); //switch the arr pointer with arr+amount
void print_array(int* arr, int len); //print array
