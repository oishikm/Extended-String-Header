#include"stringext.h"
#include<stdio.h>

int main() {
	printf("%s \n", strslice("Oishik Mukherjee", 1, 12));
	char **str = strsplit("Oishik Mukherjee is a developer", ' ');
	int i;
	for(i=0; str[i][0]!='\0'; i++) {
		printf("[%s] ", str[i]);
	}
	free(str);
	printf("\n");
	return 0;
}