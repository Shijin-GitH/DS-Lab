#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
int is_empty();
int is_full();
void insert_rear(int ele);
int delete_front();
void insert_front(int ele);
int delete_rear();
void display_queue();
void main()
{
    int option = -1;
    int element;
    do
    {
        printf(" Options \n");
        printf("-----------\n");
        printf("1. Insert to rear\n");
        printf("2. Insert to front\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Is Empty?\n");
        printf("6. Is Full?\n");
        printf("7. Display Queue\n");
        printf("8. Exit\n\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            if (is_full())
            {
                printf("Queue is full!!\n");
            }
            else
            {
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert_rear(element);
                printf("Element inserted successfully!\n");
            }
            break;
        case 2:
            if (is_full())
            {
                printf("Queue is full!!\n");
            }
            else
            {
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert_front(element);
                printf("Element inserted successfully!\n");
            }
            break;
        case 3:
            if (is_empty())
            {
                printf("Queue is empty!!\n");
            }
            else
            {
                element = delete_front();
                printf("%d delete successfully!\n", element);
            }
            break;
        case 4:
            if (is_empty())
            {
                printf("Queue is empty!!\n");
            }
            else
            {
                element = delete_rear();
                printf("%d delete successfully!\n", element);
            }
            break;
        case 5:
            if (is_empty())
                printf("Queue is Empty!!\n");
            else
                printf("Queue is not Empty!\n");
            break;
        case 6:
            if (is_full())
                printf("Queue is Full!!\n");
            else
                printf("Queue is not Full!\n");
            break;
        case 7:
            if (is_empty())
                printf("Queue is Empty!!\n");
            else
                display_queue();
            break;
        case 8:
            break;
        default:
            printf("Invalid option!! Please try again \n");
        }
        printf("\n\n");
    } while (option != 8);
}
int is_empty()
{
    if (front == -1)
        return 1;
    return 0;
}
int is_full()
{
    if ((rear + 1) % SIZE == front)
        return 1;
    return 0;
}
void insert_rear(int ele)
{
    if (++rear == SIZE)
        rear = 0;
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    queue[rear] = ele;
}

int delete_front()
{
    int ele = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (++front == SIZE)
        front = 0;
    return ele;
}
void insert_front(int ele)
{
    if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }
    queue[front] = ele;
}

int delete_rear()
{
    int ele = queue[rear];
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
    return ele;
}
void display_queue()
{
    for (int i = front; i != rear; i = ((i + 1) % SIZE))
        printf("%d ", queue[i]);
    printf("%d\n", queue[rear]);
}
