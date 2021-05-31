#include<stdio.h>

void displayArr(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
        
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for(int i = 0; i <= high; i++)
    {
        a[i] = b[i];
    }
     
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int arr[] = {12, 54, 8, 7, 23, 9, 2, 4, 78};
    int n = 9;

    displayArr(arr, n);
    mergeSort(arr, 0, n - 1);
    displayArr(arr, n);

    return 0;
}