#include"stringext.h"
#include<stdio.h>

int main() {
	printf("%s \n", strslice("Hello, World!", 2, 5));
	// strsplit() commented out for now: Investigating segmentation fault at strsplit() call
	/*char **str = strsplit("C is a powerful programming language", ' ');
	int i;
	for(i=0; str[i][0]!='\0'; i++) {
		printf("[%s] ", str[i]);
	}
	free(str);*/
	char str1[] = "  hello world  ";
	strstrip(str1);
	printf("\nTrimmed string : [%s] \n", str1);
	printf("\n");
	return 0;
}
