#include <stdio.h>
#include <stdlib.h>

// main funcs
int getLine(char s[]); // get chars to create a string, return length, #define LINE 256
int getword(char w[]); // get chars to create a string, return length, #define WORD 30
int substring(char* str1, char* str2); // checks if str1 contains str2
int similar(char* s, char* t, int n); // checks if by removing n chars from s you get t, retrun 1/0 (t,f)
void print_lines(char* str); // gets keyword and prints line with the keyword
void print_similar_words(char* str); // gets keyword and prints all similar words

// helper funcs
int substringhelper(char* str1, char* str2, int len, int move);