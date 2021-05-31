#include <stdio.h>

void displayArr(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{

    int pivot = arr[low];
    int temp;
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;

}

void quickSort(int *arr, int low, int high)
{

    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {

        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // sort left subarray
        quickSort(arr, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{

    int arr[] = {12, 54, 65, 45, 28, 9, 23, 78};
    int n = 8;

    displayArr(arr, n);
    quickSort(arr, 0, n - 1);
    displayArr(arr, n);
    return 0;
}