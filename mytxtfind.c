#include "mytxtfind.h"
#include <string.h>

#define LINE 256
#define WORD 30

int getLine(char s[])
{
	int i = 0;
	char c;
	while((c=getchar())!='\n' && c!=EOF)
	{
		s[i] = c;
		++i;
	}
	if (i == 0) 
		return -1;
	s[i] = '\0';
	if (c == EOF)
		++i;
	return i;
}
int getword(char w[])
{	
	int i = 0;
	char c = getchar();
	while(c != ' ' && c != '\n' && c!=EOF) //&& c!='\t'
	{
		w[i] = c;
		++i;
		c = getchar();
	}
	if (c == '\n')
	{
		--i;
	}
	if (i == 0) 
		return -1;
	w[i] = '\0';
	return i;
}
int substring(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 == 0 || len2 == 0)
		return 0;
	if (len2 > len1)
		return 0;
	for (int i = 0; i < len1-len2+1; ++i)
	{
		if (str1[i] == str2[0])
		{
			if(substringhelper(str1, str2, len2, i))
			{
				return 1;
			}
		}
	}
	return 0;
}
int substringhelper(char* str1, char* str2, int len, int move)
{
	for (int i = 0; i < len; ++i)
	{
		if (str1[move+i] != str2[i])
		{
			return 0;
		}
	}
	return 1;
}
int similar(char* s, char* t, int n)
{
	if (strlen(s) < strlen(t))
		return 0;
	int move = 0;
	for (int i = 0; i < strlen(t) && n != -1; ++i)
	{
		if (s[move+i] != t[i])
		{
			--i;
			++move;
			--n;
		}
	}
	if (n < 0)
		return 0;
	move += n;
	if (strlen(s) > strlen(t) + move)
		return 0;
	return 1;
}
void print_lines(char* str)
{
	int len;
	char buffer[LINE];

	len = getLine(buffer);
	while(len != -1) 
    {
    	if (substring(buffer, str))
    	{
    		printf("%s\n", buffer);
    	}
	    len = getLine(buffer);
    }
}
void print_similar_words(char* str)
{
	int len;
	char buffer[LINE];

	len = getword(buffer);
	len = getword(buffer);
	while(len != -1) 
	{
		if (similar(buffer, str, 1))
		{
			printf("%s\n", buffer);
		}
	    len = getword(buffer);
	}
}