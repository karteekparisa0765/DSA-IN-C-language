#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[1000];
    FILE *ptr1, *ptr2;

    // Writing names to sample.txt
    ptr1 = fopen("sample.txt", "w");
    if (ptr1 == NULL)
    {
        printf("Error opening sample.txt for writing!\n");
        return 1;
    }

    int x;
    printf("Please enter the number of names to be inserted: ");
    scanf("%d", &x);
    getchar(); // Consume newline character left in the input buffer

    for (int i = 0; i < x; i++)
    {
        printf("Enter the name %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        fputs(name, ptr1);
    }
    fclose(ptr1);

    // Reading from sample.txt and writing to filetofile.txt
    ptr1 = fopen("sample.txt", "r");
    if (ptr1 == NULL)
    {
        printf("Error opening sample.txt for reading!\n");
        return 1;
    }

    ptr2 = fopen("filetofile.txt", "w");
    if (ptr2 == NULL)
    {
        printf("Error opening filetofile.txt for writing!\n");
        fclose(ptr1);
        return 1;
    }
    while (!feof(ptr1))
    {
        fgets(name, sizeof(name), ptr1);
        if(!feof(ptr1)){
            fputs(name,ptr2);
        }
    }

    fclose(ptr1);
    fclose(ptr2);

    return 0;
}
