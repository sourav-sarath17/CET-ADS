#include<stdio.h>
void main()
{
    
    int n,ch;
    char flg='y';
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    while(flg=='y'){
    printf("\nEnter the choice 1. display 2. Search 3. Sort 4. Insert 5. Delete: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:display(A,n);
        break;
        case 2:search(A,n);
        break;
        case 3:sort(A,n);
        break;
        case 4:insert(A,n);
        break; 
        case 5:del(A,n);
        break;
    }
    printf("\nPress y to continue or n to exit: ");
    scanf(" %c",&flg);
}

}

void display(int A[], int n)
{
    printf("\n");
    for(int i=0;i<n;i++){
        printf("\t%d",A[i]);
    }
}

void search(int A[],int n)
{
    int a;
    printf("\nEnter element to be searched: ");
    scanf("%d", &a);
    int flag=0;
    for(int i=0;i<n;i++){
        if(A[i]==a){
            printf("\nElement found at index %d",i+1);
            flag=1;
            break;
        }
        
    }
    if(flag==0)
    printf("\nElement not found");

}
void sort(int A[],int n)
{
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j])
            {
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
        display(A,n);

}

void insert(int A[],int n)
{
    int e,pos;
    printf("\nEnter element to be inserted: ");
    scanf("%d",&e);
    printf("\nEnter position to insert element: ");
    scanf("%d",&pos);
    n=n+1;
    for(int i=n-1;i>=pos;i--){
        A[i]=A[i-1];
    }
    A[pos-1]=e;
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
void del(int A[],int n)
{
    int pos;
    printf("\nEnter position to delete element: ");
    scanf("%d",&pos);
    for(int i=pos-1;i<n-1;i++){
        A[i]=A[i+1];
    }
    n=n-1;
    display(A,n);
}