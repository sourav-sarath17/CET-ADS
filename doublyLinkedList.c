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
        printf("Enter 1 to Enqueue, 2 to display,3 to Dequeue, 0 to exit: ");
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
            disprev();
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

void disprev()
{
    for (current = newnode; current != head; current = current->prev)
    {
        printf("%d ", current->data);
    }
    
    printf("%d ", *head);
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
