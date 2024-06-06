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

void traverse(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->next == NULL) {
            printf("%s --> NULL\n", ptr->name);
        } else {
            printf("%s --> ", ptr->name);
        }
        ptr = ptr->next;
    }
}

struct node *deleteAlphabetOccurrences(struct node *head, char ch) {
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL) {
        if (current->name[0] == ch) {
            // Node contains the specified alphabet, delete it
            struct node *temp = current;
            if (prev != NULL) {
                prev->next = current->next;
                current = current->next;
                free(temp);
            } else {
                // Deleting the first node
                head = current->next;
                free(temp);
                current = head;
            }
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }

    return head;
}

int main() {
    int n;
    printf("please enter the number of nodes:");
    scanf("%d", &n);

    char name[100];
    struct node *head = NULL;

    for (int i = 0; i < n; i++) {
        printf("please enter the name of student:");
        scanf("%s", name);
        head = createnode(name);
        head->next = head;
    }

    // Linking the nodes
    for (int i = 0; i < n - 1; i++) {
        head->next = createnode(name);
        head = head->next;
    }

    head = deleteAlphabetOccurrences(head, 'A'); // Replace 'A' with the desired alphabet

    printf("Linked List after deletion:\n");
    traverse(head);

    return 0;
}
