#include<stdio.h>
#include<conio.h>
void main()
{
    int ar1[50], ar2[50], finalarr[100];
    int i, m,n, sum = 0;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &m);
    printf("Enter the elements of the second array:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &ar2[i]);
    }
    for( i=0;i<n+m;i++)
    {
        if(i<n)
        {
            finalarr[i]=ar1[i]; 
        }
        else
        {
            finalarr[i]=ar2[i-n];
        }

    }
    printf("Final Array is \n");
    for (i=0;i<n+m;i++)
    {
        printf("%d \n",finalarr[i]);
    }
    
}