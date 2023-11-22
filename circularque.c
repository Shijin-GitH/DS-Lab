#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    else
        return 0;
}

void insertToRear(int element)
{
    if (isFull())
    {
        printf("Queue is full. Cannot insert element.\n");
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = element;
        printf("Element inserted successfully!\n");
    }
}

int deleteFromFront()
{
    int element;
    if (isEmpty())
    {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    }
    else
    {
        element = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return element;
    }
}

int main()
{
    int option, element;

    do
    {
        printf("Options\n");
        printf("1. Insert to rear\n");
        printf("2. Delete from front\n");
        printf("3. Is Empty?\n");
        printf("4. Is Full?\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertToRear(element);
            break;
        case 2:
            element = deleteFromFront();
            if (element != -1)
                printf("Deleted element: %d\n", element);
            break;
        case 3:
            if (isEmpty())
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 4:
            if (isFull())
                printf("Queue is full.\n");
            else
                printf("Queue is not full.\n");
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

        printf("\n");
    } while (option != 5);

    return 0;
}
