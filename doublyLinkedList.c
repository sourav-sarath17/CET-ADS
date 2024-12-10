#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode, *current, *head = NULL;
void main()
{

    int i, n, ch = 1;
    while (ch != 0)
    {
        printf("Enter 1 to Insert at End, 2 to display,3 to Delete from end,4 to delete from start, 5 to insert at beginning,6 to insert at a position, 7 to delete from position, 0 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enq();
            break;
        case 2:
            disp();
            break;
        case 3:
            deq();
            break;
        case 4:
            delAtBeg();
            break;
        case 5:
            insAtBeg();
            break;
        case 6:
            insAtPos();
            break;
        case 7:
            delFromPos();
            break;
        }
    }
}
void enq()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Node data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        current = newnode;
        current->prev = head;
    }
    else
    {

        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }
    current->next = NULL;
}
void disp()
{
    for (current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
    printf("\n");
}

void deq()
{
    for (current = head; current != NULL; current = current->next)
    {
        if (current->next->next == NULL)
        {
            current->next = NULL;
        }
    }
}
void insAtBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Node data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insAtPos()
{
    int pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Node data: ");
    scanf("%d", &newnode->data);
    for (current = head, i = 1; current != NULL; current = current->next, i++)
    {
        if (i == pos - 1)
        {
            newnode->next = current->next;
            current->next = newnode;
            newnode->prev = current;
            break;
        }
    }
}
void delAtBeg()
{
    current = head;
    head = current->next;
    current = NULL;
}
void delFromPos()
{

    int pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    for (current = head, i = 1; current != NULL; current = current->next, i++)
    {
        if (i == pos - 1)
        {
            current->next = current->next->next;
            current->next->next->prev = current;
        }
    }
}
