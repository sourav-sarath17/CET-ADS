#include <stdio.h>
void main()
{
    int U[50], n;
    printf("Enter the number of elements in the Universal set: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &U[i]);
    }
    int set1[50], n1;
    int set2[50], n2;
    printf("Enter the number of elements in Set 1: ");
    scanf("%d", &n1);
    printf("Enter the elements of the Set 1:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &set1[i]);
    }
    printf("Enter the number of elements in Set 2: ");
    scanf("%d", &n2);
    printf("Enter the elements of the Set 2:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &set2[i]);
    }
    int bit1[n1], bit2[n2];
    for (int i = 0; i < n1; i++)
    {
        bit1[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (U[j] == set1[i])
            {
                bit1[i] = 1;
            }
        }
    }
    for (int i = 0; i < n2; i++)
    {
        bit2[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (U[j] == set2[i])
            {
                bit2[i] = 1;
            }
        }
    }

    printf("Bit String Set 1:");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", bit1[i]);
    }
    printf("\nBit String Set 2:");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", bit2[i]);
    }
    int big;
    if (n1 > n2)
    {
        big = n1;
    }
    else
    {
        big = n2;
    }
    int setUnion[big], setInt[big];
    for (int i = 0; i < big; i++)
    {
        setUnion[i] = 0;
        if (bit1[i] == 1 || bit2[i] == 1)
        {
            setUnion[i] = 1;
        }
    }
    for (int i = 0; i < big; i++)
    {
        setInt[i] = 0;
        if (bit1[i] == 1 && bit2[i] == 1)
        {
            setInt[i] = 1;
        }
    }
    printf("\nSet Union:");
    for (int i = 0; i < big; i++)
    {
        printf("%d ", setUnion[i]);
    }
    printf("\nSet Intersection:");
    for (int i = 0; i < big; i++)
    {
        printf("%d ", setInt[i]);
    }
}