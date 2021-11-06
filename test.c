#include"stringext.h"
#include<stdio.h>

int main() {
	printf("Sliced string is : [%s]", strslice("Hello, World!", 2, 5));
	char **str = strsplit("C is a powerful programming language", ' ');
	printf("\nSplit string : ");
	int i;
	for(i=0; str[i][0]!='\0'; i++) {
		printf("[%s] ", str[i]);
	}
	free(str);
	char str1[] = "  hello world  ";
	strstrip(str1);
	printf("\nTrimmed string : [%s] \n", str1);
	printf("\n");
	return 0;
}
