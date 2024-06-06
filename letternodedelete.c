#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[100];
    struct node *next;
};

struct node *createnode(char *name) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->name, name);
    ptr->next = NULL;
    return ptr;
}

struct node *deleteNodes(struct node *head, char ch) {
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    dummy->next = head;
    struct node *prev = dummy;
    struct node *current = head;

    while (current != NULL) {
        if (current->name[0] == ch) {
            prev->next = current->next;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    head = dummy->next;
    return head;
}

void traverse(struct node *head) {
    struct node *ptr;
    ptr = head;
    while (ptr != NULL) {
        if (ptr->next == NULL) {
            printf("%s --> NULL\n", ptr->name);
        } else {
            printf("%s --> ", ptr->name);
        }
        ptr = ptr->next;
    }
}

int main() {
    int n;
    printf("Please enter the number of nodes: ");
    scanf("%d", &n);

    char name[100];
    struct node *ptr[n];

    for (int i = 0; i < n; i++) {
        printf("Please enter the name of student: ");
        scanf("%s", name);
        ptr[i] = createnode(name);
    }

    // Linking the nodes
    for (int i = 0; i < n - 1; i++) {
        ptr[i]->next = ptr[i + 1];
    }

    struct node *head = ptr[0];
    traverse(head);

    printf("Please enter the first letter to delete all occurrences: ");
    char ch;
    scanf(" %c", &ch);

    head = deleteNodes(head, ch);
    traverse(head);

    return 0;
}
