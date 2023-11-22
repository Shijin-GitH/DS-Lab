#include <stdio.h>

void quickSort();
int partition();
void swap();

void main()
{
    int n, i;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p+1, high);
    }
}

int partition(int a[], int low, int high)
{
    int i = low-1;
    int pivot = a[high];

    for (int j = low + 1; j <= high - 1; j++)
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
        swap(&a[i+1], &a[high]);
        return(i+1);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}