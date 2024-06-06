#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    fptr = fopen("hello.txt", "w");
    fprintf(fptr, "hello");
    // fputc('character to input',pointer name);
    // fputs("string to be input",pointer name);
    // fputs("name:",fptr);
    // fprintf("pointer name","format specifier",information);
//fgets(str,sizeof(),pointer name);
    return 0;
}