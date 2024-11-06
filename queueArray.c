#include<stdio.h>
#include<conio.h>
void main()
{
    int que[20];
    int front=-1,rear=-1,ch,flag=1;
    //Enque
    int size=0;
    printf("\nEnter size of array: ");
    scanf("%d",&size);
    while (flag==1)
    {
    printf("\nEnter choice \n1. Enqueue \n2. Dequeue \n3. Display:  ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    front++;
    for(int i=0;i<size;i++)
    {
    if(rear==size-1)
    {
        printf("\nQueue is full");
        break;
        }
        else{
            rear++;
            printf("\nEnter element to be inserted: ");
            scanf("%d",&que[rear]);
        }
        }
        break;
        case 2:
        if(front==-1)
        {
            printf("\nQueue is empty");
            break;
        }
        else{
            front++;

        }
        break;
        case 3:
        printf("\n");
        for( int i=front;i<size;i++)
        {
            printf("%d ",que[i]);
        }
    }
    printf("\n Press 1 to continue: ");
    scanf("%d",&flag);
}


}
