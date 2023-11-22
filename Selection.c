#include <stdio.h>

void Sort();

void main()
{
    int n,i;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d numbers: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    Sort(a,n);
    printf("Sorted Array: ");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

void Sort(int a[], int n)
{
    int i,j,min;
    for(i=0; i<n; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
            if(a[min] > a[j])
                min = j;
        if(min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}