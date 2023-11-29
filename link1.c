#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} Node;
Node *HEAD = NULL;
void insert_first(int ele);
void insert_last(int ele);
void insert_before(int val, int ele);
void insert_after(int val, int ele);
void delete(int ele);
int is_empty();
void show_list();
int main()
{
    int option = -1;
    int element, val;
    do
    {
        printf(" Options \n");
        printf("-----------\n");
        printf("1. Insert first\n");
        printf("2. Insert last\n");
        printf("3. Insert after a node\n");
        printf("4. Insert before a node\n");
        printf("5. Delete node\n");
        printf("6. Is Empty?\n");
        printf("7. Display list\n");
        printf("8. Exit\n\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert_first(element);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert_last(element);
            break;
        case 3:
            printf("Enter the value of the node to insert after: ");
            scanf("%d", &val);
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert_after(val, element);
            break;
        case 4:
            printf("Enter the value of the node to insert before: ");
            scanf("%d", &val);
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert_before(val, element);
            break;
        case 5:
            printf("Enter the element to delete: ");
            scanf("%d", &element);
            delete (element);
            break;
        case 6:
            if (is_empty())
                printf("List is Empty!!\n");
            else
                printf("List is not Empty!\n");
            break;
        case 7:
            if (is_empty())
                printf("List is Empty!!\n");
            else
                show_list();
            break;
        case 8:
            break;
        default:
            printf("Invalid option!! Please try again \n");
        }
        printf("\n\n");
    } while (option != 8);
    return 0;
}
void insert_first(int ele)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->info = ele;
    tmp->link = HEAD;
    HEAD = tmp;
    printf("Element inserted successfully!\n");
}
void insert_last(int ele)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->info = ele;
    tmp->link = NULL;
    if (HEAD == NULL)
    {
        HEAD = tmp;
        return;
    }
    Node *curr = HEAD;
    while (curr->link != NULL)
    {
        curr = curr->link;
    }
    curr->link = tmp;
    printf("Element inserted successfully!\n");
}
void insert_before(int val, int ele)
{
    Node *curr = HEAD;
    Node *prev;
    while (curr != NULL && curr->info != val)
    {
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL)
    {
        printf("No such element\n");
        return;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->info = ele;
    tmp->link = curr;
    if (curr == HEAD)
        HEAD = tmp;
    else
        prev->link = tmp;
    printf("Element inserted successfully!\n");
}
void insert_after(int val, int ele)
{
    Node *curr = HEAD;
    while (curr != NULL && curr->info != val)
    {
        curr = curr->link;
    }
    if (curr == NULL)
    {
        printf("No such element\n");
        return;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->info = ele;
    tmp->link = curr->link;
    curr->link = tmp;
    printf("Element inserted successfully!\n");
}
void delete(int ele) {
    Node *curr = HEAD;
    Node *prev = NULL;

    while (curr != NULL && curr->info != ele) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        printf("No such element\n");
        return;
    }

    if (prev == NULL) {
        HEAD = curr->link;
    } else {
        prev->link = curr->link;
    }

    free(curr);
    printf("Element deleted successfully!\n");
}

int is_empty()
{
    if (HEAD == NULL)
        return 1;
    return 0;
}
void show_list()
{
    Node *curr = HEAD;
    while (curr != NULL)
    {
        printf("%d ", curr->info);
        curr = curr->link;
    }
    printf("\n");
}