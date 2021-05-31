#include<stdio.h>

void insertionSort(int *arr, int n) {

    int key, j;
    for(int i = 1; i <= n -1; i++) {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void displayArr(int *arr, int n) {

    for(int i = 0; i < n; i++) {

        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insertArr(int *arr, int n)
{
    printf("Enter elements in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
}

int main() {

    // int arr[]  = {12, 54, 65, 7, 23, 9};
    // int n = 6;

    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int arr[n];

    insertArr(arr, n);
    displayArr(arr, n);
    insertionSort(arr, n);
    displayArr(arr, n);

    return 0;
}