#include<stdio.h>

void displayArr(int *arr, int n) {

    for(int i = 0; i < n; i++) {

        printf("%d\t", arr[i]);
    }
    printf("\n");

}

void selectionSort(int *arr, int n)
{
    int indexOfMin, temp;
    for(int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{
    int arr[]  = {12, 54, 36, 7, 23, 9};
    int n = 6;

    displayArr(arr, n);
    selectionSort(arr, n);
    displayArr(arr, n);

    return 0;
}