#include"stringext.h"
#include<stdio.h>

int main() {
	printf("%s \n", strslice("Oishik Mukherjee", 1, 12));
	char **str = strsplit("Oishik Mukherjee is a programmer", ' ');
	int i;
	for(i=0; str[i][0]!='\0'; i++) {
		printf("[%s] ", str[i]);
	}
	free(str);
	char str1[] = "  hello world  ";
	strtrim(str1);
	printf("\nTrimmed string : [%s] \n", str1);
	printf("\n");
	return 0;
}