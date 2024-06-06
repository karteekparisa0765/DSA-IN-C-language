// train name
// train number
// source station
// source destination
// arrange using distannce
// sort them and display
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char name[100];
    int number;
    char sstation[100];
    char destination[100];
    int distance;
    struct node *next;
};

struct node *createnode(int number, char *name, char *sstation, char *destination, int distance)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->number = number;
    strcpy(ptr->name, name);
    strcpy(ptr->sstation, sstation);
    strcpy(ptr->destination, destination);
    ptr->distance = distance;
    return ptr;
}
struct node *sort(struct node *head)
{
    struct node *i;
    struct node *j;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->distance > j->distance)
            {
                temp->distance = j->distance;
                temp->number = j->number;
                strcpy(temp->destination, j->destination);
                strcpy(temp->name, j->name);

                strcpy(temp->sstation, j->sstation);

                j->distance = i->distance;
                j->number = i->number;
                strcpy(j->destination, i->destination);
                strcpy(j->name, i->name);

                strcpy(j->sstation, i->sstation);

                i->distance = temp->distance;
                i->number = temp->number;
                strcpy(i->destination,temp->destination);
                strcpy(i->name,temp->name);
                strcpy(i->sstation,temp->sstation);
            }
        }
    }
    return head;
}
void traverse(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){

if(ptr->next==NULL){
    printf("train number:%d--train name:%s--starting from:%s--departing at:%s--distance:%d-->NULL",ptr->number,ptr->name,ptr->sstation,ptr->destination,ptr->distance);
}
else{
        printf("train number:%d--train name:%s--starting from:%s--departing at:%s--distance:%d-->",ptr->number,ptr->name,ptr->sstation,ptr->destination,ptr->distance);

}
ptr=ptr->next;




    }
}
int main()
{
    char name[100];
    int number;
    char sstation[100];
    char destination[100];
    int distance;
    int n;
    printf("please enter the number of trains in todays chart:");
    scanf("%d", &n);
    struct node *trains[n];
    for (int i = 0; i < n; i++)
    {
        printf("please enter the train number:");
        scanf("%d", &number);
        printf("please enter the train name:");
        scanf("%s", name);
        printf("please enter the boarding station name:");
        scanf("%s", sstation);
        printf("please enter the departing station name:");
        scanf("%s", destination);
        printf("please enter the distance bewteen the stations:");
        scanf("%d", &distance);
        trains[i] = createnode(number, name, sstation, destination, distance);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            trains[i]->next = NULL;
        }
        else
        {
            trains[i]->next = trains[i + 1];
        }
    }

    struct node *head = trains[0];
    head = sort(head);
    traverse(head);
    return 0;
}