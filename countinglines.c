#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[1000];
    FILE *ptr;
    ptr = fopen("new.txt", "w");
    if (ptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    
    printf("\n1) Add name\n2) Exit\n");
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                getchar(); // Clearing input buffer
                printf("Enter the string to be entered: ");
                fgets(name, sizeof(name), stdin);
                fputs(name, ptr);
                break;
                case 2:{
                    printf("thanks for adding the names\n");
                }
                break;
            default:

                printf("Please enter the valid choice!!\n");
                break;
        }
    } while (choice != 2);
    
    fclose(ptr);

    // Opening the file again in read mode
    ptr = fopen("new.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file!");
        return 1;
    }

    char ch;
    int count = 0;
    while (!feof(ptr)) {
        ch = fgetc(ptr);
        if (ch == '\n') {
            count++;
        }
    }
    fclose(ptr);

    printf("Number of lines: %d\n", count);

    return 0;
}
