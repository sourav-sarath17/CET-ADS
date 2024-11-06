#include<stdio.h>
#include<conio.h>
void main()
{
    int stk[20];
    int i,n, top=-1, ch,flag=1;
    do
    {
    printf("Enter choice: \n1. Push \n2. Pop \n3. Display \n4.Peek: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        top++;
        int num=0;
        printf("Enter number: ");
        scanf("%d",&num);
        stk[top]=num;
        break;
    case 2:
        if(top==-1)
        {
            printf("\nUnderflow");
            return;
        }
        else{
            printf("\nDeleted element: %d",stk[top]);
            top--;
        }
        break;
    case 3:
        if(top==-1)
        {
            printf("\nEmpty");
        } 
        for (int i=0;i<=top;i++)
        {
            printf("%d \n",stk[i]);
        }
            break;
    case 4:
        printf("Top is %d", stk[top]);
        default:
            break;
    }
    printf("\n Press 1 to continue: ");
    scanf("%d",&flag);
    }while(flag==1);

}

