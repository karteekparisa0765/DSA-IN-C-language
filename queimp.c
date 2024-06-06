#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
/*in this progrramme we will be performing different operation on the ques and the operations are listed below
1)ENQUE
2)DEQUE
3)DISPLAY
DATED:17-02-2024
*/

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

int isEmpty()
{
    return (front == -1 && rear == -1);
}

int isFull()
{
    return (rear == MAX_SIZE - 1);
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = data;
    printf("the enqued data is %d.\n", data);
}

int dequeue()
{
    int data;

    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    data = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    return data;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    int data;

    do
    {
        printf("\n-------que------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
