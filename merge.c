#include <stdio.h>

void mergeSort();
void merge();

void main()
{
    int n, i;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, x, y, b[high + 1], k;
    for (i = low, x = low, y = mid + 1; x <= mid && y <= high; i++)
    {
        if (a[x] <= a[y])
        {
            b[i] = a[x];
            x++;
        }
        else
        {
            b[i] = a[y];
            y++;
        }
    }
    while (x <= mid)
    {
        b[i] = a[x];
        x++;
        i++;
    }
    while (y <= high)
    {
        b[i] = a[y];
        y++;
        i++;
    }
    for (k = low; k <= high; k++)
        a[k] = b[k];
}