/*  
 *   stringext.h
 *   String Library Extension
 *   Oishik M | 12 September 2019
 */

#ifndef _STRING_H_
#include<string.h>
#endif

#ifndef _STDLIB_H_
#include<stdlib.h>
#endif

#define MAXSTRSIZE 1024
#define MAXSPLIT 100

char *strslice(char instr[], int start, int end) {
    /*
     *   Returns substring from instr[start] to instr[end-1]
     */

    char* outstr = (char *)malloc(MAXSTRSIZE * sizeof(char));
    register int i, k;
    for(i=start, k=0; instr[i]!='\0' && i<end && i<MAXSTRSIZE; i++, k++) {
        outstr[k] = instr[i];
    }
    outstr[k] = '\0';
    return outstr;
}

char **strsplit(char instr[], char token) {
    /*
     *   Splits input string into substrings when separated by token character.
     *   Maximum MAXSPLIT substrings may be returned.
     */

    char** outstr = (char **)malloc(MAXSPLIT * sizeof(char *));
    register int i, j, start;
    for(i=0; i<MAXSPLIT; i++) {
        outstr[i] = (char *)malloc(MAXSTRSIZE * sizeof(char));
        outstr[i][0] = '\0';
    }
    for(i=0, j=0, start=0; instr[i]!='\0' && j<MAXSPLIT-1; i++) {
        if(instr[i] == token) {
            strcpy(outstr[j++], strslice(instr, start, i));
            start = i+1;
        }
    }
    strcpy(outstr[j], strslice(instr, start, i));
    return outstr;
}