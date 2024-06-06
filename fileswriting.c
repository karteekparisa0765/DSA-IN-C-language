#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[1000];
    FILE *ptr;
    ptr = fopen("write.txt", "w");
    if (ptr == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    printf("please enter the number of names to be inserted:");
    int x;
    scanf("%d", &x);
    getchar(); // consume newline character left in the input buffer
    for (int i = 0; i < x; i++)
    {
        printf("Enter name %d: ", i + 1);
        //gets(name); GIVES THE OUT PUT NAMES IN ONE LINE
        //FGETS(NAME,SIZEOF(NAME),STDIN); ENABLES TO ENTER IN DIFFERENT LINES AS CONSUMES THE NEW LINE \N
        //fgets(name,sizeof(name),pointer name) for reading from the file
        
        fgets(name,sizeof(name),stdin);
        fputs(name, ptr);
    }
    fclose(ptr);

    return 0;
}
