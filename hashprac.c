#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 11
struct node
{
    int data;
    struct node *next;
};
struct node *table[size];
void createtable()
{
    for (int i = 0; i < size; i++)
    {
        table[i] = NULL;
    }
}
void insert(int n){
    int hv=n%size;
    struct node *node=(struct node *)malloc(sizeof(struct node));
    if(table[hv]==NULL){
        table[hv]=node;
    }
    else{
        struct node *temp=table[hv];
        while
    }
}

int main()
{

    return 0;
}