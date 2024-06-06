#include <stdio.h>
// name and branch
#include <stdlib.h>
#include <string.h>

#define size 10 
int f = -1;
int r = -1;
struct student
{
    char name[100];
    char branch[100];
};
    void display();
    void deque();
    void enque(char *name, char *branch);

struct student que[size];

void enque(char *name, char *branch)
{
    if (f == r && r == (size - 1))
    {
        printf("Sorry... queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f++;
        r++;
        strcpy(que[r].name, name);
    strcpy(que[r].branch, branch);
    }
    else
    {
        r++;
    strcpy(que[r].name, name);
    strcpy(que[r].branch, branch);
    }
}
void deque()
{
    if (f == r == -1)
    {
        printf("que is empty");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else
    {
        printf("dequed student is:%s", que[f].name);
        printf("dequed student branch is:%s", que[f].branch);
        f++;
    }
}
    void display()
    {
        int i;
        if (f == -1 && r == -1)
        {
            printf("que is empty\n");
        }
        else
        {
            for (i = f; i <= r; i++)
            {
                printf("student[%d].name=%s\n", i + 1, que[i].name);
                printf("student[%d].branch=%s\n", i + 1, que[i].branch);
            }
        }
    }

    int main()
    {
        printf("please enter the choice to proceed");
        int choice;
        char name[100];
        char branch[100];
        do{
            printf("\n");
        printf("1)enque\n2)deque\n3)display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the name of student:");
            scanf("%s", name);
            printf("please enter the branch of the student:");
            scanf("%s", branch);
            enque(name, branch);
        }
        break;
        case 2:
        {
            deque();
        }
        break;
        case 3:
        {
            display();
        }
        break;
        case 4:
        {
            printf("exitting the console...");
        }
        break;
        default:
        {
            printf("enter the valid choice");
        }
        }}while(choice!=4);

        return 0;
    }