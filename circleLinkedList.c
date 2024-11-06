#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *current, *head = NULL, *tail;
void main()
{

    int i, n, ch = 1;
    while (ch != 0)
    {
        printf("Enter 1 to insert, 2 to display,3 to delete, 4 to insert at start, 5 to delete from start, 0 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtEnd();
            break;
        case 2:
            disp();
            break;
        case 3:
            delFromEnd();
            break;
        case 4:
            insertAtBeg();
            break;
        
        case 5:
            delFromBeg();
            break;
        }
    }
}
void insertAtEnd()
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
        current->next = newnode;
        current = newnode;
    }
    current->next = head;
    tail = current;
}

void insertAtBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Node data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void disp()
{
    for (current = head; current != tail; current = current->next)
    {
        printf("%d ", current->data);
        if (current->next == tail)
        {

            printf("%d ", tail->data);
        }
    }
    printf("\n");
}
void delFromEnd()
{

    for (current = head; current!=tail; current = current->next)
    {
        if (current->next->next == head)
        {
            current->next = head;
            tail=current;
            break;

        }
    }
}
void delFromBeg()
{
    current=head;
    head=current->next;
}