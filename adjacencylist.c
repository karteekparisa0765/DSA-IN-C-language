#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
    int data;
    struct node *next;
};

struct node *adjacencylist(struct node **adj,int vertex){
for (int i = 0; i <vertex ; i++)
{
printf("enter the number of neighbours %d ",){}



}



}


int main() {
    printf("please enter the number of vertices in the graph:");
    int vertex;
    scanf("%d",&vertex);
    struct node *adj[vertex];
    for (int i = 0; i < vertex; i++)
    {
        adj[i]=NULL;
    }
    adjacencylist(adj,vertex);
    
    
    return 0;
}