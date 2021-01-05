#include <stdio.h>
#include "mytxtfind.h"

#define LINE 256
#define WORD 30

int main() 
{	
	char keyword[WORD];
	int keywordlen = getword(keyword);
	// printf("%s\n", keyword);
 //    printf("%d\n", keywordlen);

    char type[WORD];
    int len = 1;
	char buffer[LINE];


    if (getword(type) != 1)
    {
    	printf("%s is not of valid length\n", keyword);
    }
    else if (type[0] == 'a')
    {
    	len = getLine(buffer);
    	while(len != -1) 
	    {
	    	if (substring(buffer, keyword, len, keywordlen))
	    	{
	    		printf("%s\n", buffer);
	    	}
		    len = getLine(buffer);
	    }
    }
    else if (type[0] == 'b')
    {
    	len = getword(buffer);
    	len = getword(buffer);
    	while(len != -1) 
	    {
	    	if (similar(buffer, keyword, 1))
	    	{
	    		printf("%s\n", buffer);
	    	}
	    	// else
	    	// {
	    	// 	printf("---%s\n", buffer);	
	    	// }
		    len = getword(buffer);
	    }
    }
    else
    {
    	printf("%s is not a valid option\n", type);
    }

  //   len = getLine(buffer);
    
    
	// char s[LINE];
	// scanf("%s", s);

	// for (int i = 0; i < LINE; ++i)
	// {
	// 	printf("%s\n", s);
	// }

	// FILE* filePointer;
	// int bufferLength = 255;
	// char buffer[bufferLength];

	// filePointer = fopen("file.txt", "r");

	// while(fgets(buffer, bufferLength, filePointer)) {
	//     printf("%s\n", buffer);
	// }

	// fclose(filePointer);

	return 0;
}