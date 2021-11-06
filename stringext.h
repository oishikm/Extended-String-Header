/*  
 * stringext.h
 * String Library Extension
 * Oishik M | 12 September 2019
 */

#ifndef _STRING_H_
#include<string.h>
#endif

#ifndef _STDLIB_H_
#include<stdlib.h>
#endif

#ifndef _STRINGEXT_H_
#define _STRINGEXT_H_

char *strslice(char* instr, int start, int end) {
    /*
     * Returns substring from instr[start] to instr[end-1]
     */

    char* outstr = (char *)malloc((end - start + 1) * sizeof(char));
    register int i, k;
    for(i=start, k=0; instr[i]!='\0' && i<end; i++, k++) {
        outstr[k] = instr[i];
    }
    outstr[k] = '\0';
    return outstr;
}

char **strsplit(char* instr, char token) {
    /*
     * Splits input string into substrings when separated by token character.
     */

    register int i, j, start;
    int count = 1;  /* 1 extra for terminator string at end */
    int maxlen = 0; /* Maximum length of the member substrings */
    int len = 0;    /* Counter for length of each substring */
    
    for(i=0; instr[i]!='\0'; i++) {
        if(instr[i] == token) {
            count++;
            if(len>maxlen) {
                maxlen = len;
            }
            len = 0;
        }
        else {
            len++;
        }
    }

    char** outstr = (char **)malloc(count * sizeof(char *));
    for(i=0; i<=count; i++) {
        outstr[i] = (char *)malloc(maxlen * sizeof(char));    
    }
    outstr[i-1][0] = '\0';    /* Ending terminator string */
    for(i=0, j=0, start=0; instr[i]!='\0' && j<count; i++) {
        if(instr[i] == token) {
            strcpy(outstr[j++], strslice(instr, start, i));
            start = i+1;
        }
    }
    strcpy(outstr[j], strslice(instr, start, i));
    return outstr;
}

void strstrip(char* instr) {
    /*
     * Trims starting and trailing whitespace in passed string.
     */

    register int i;
    int n = strlen(instr);
    for(i=0; instr[i]==' '; i++)
        ;
    strcpy(instr, strslice(instr, i, n));
    n = strlen(instr);
    for(i=n-1; instr[i]==' '; i--)
        ;
    instr[i+1] = '\0';
}

#endif /* _STRINGEXT_H_ */
