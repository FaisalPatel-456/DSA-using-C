#include<stdio.h>

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


// adaptive bubble sort algorithm
void bubbleSort(int *arr, int n) {

    int temp;
    int isSorted = 0;
    for(int i = 0; i < n-1; i++) {   //for number of passes

        isSorted = 1;
        printf("Working on pass %d\n", i+1);
        for(int j = 0; j < n-1-i; j++) {     //for number of swaps

            if(arr[j] > arr[j+1]) {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;

            }
            
        }
        if(isSorted) {

            return;
        }
    }

}

int main() {

    //int arr[] = {12, 54, 65, 7, 23, 9};      // unsorted array
    //int arr[] = {1, 2, 3, 4, 5, 6};           // sorted array
    //int arr[] = {3, 2, 1, 4, 5, 6};            // partially sorted array
    int n;

    printf("Enter no of elements\n");
    scanf("%d", &n);
    int arr[n];

    insertArr(arr, n);
    displayArr(arr, n);
    bubbleSort(arr, n);
    displayArr(arr, n);

    return 0;

}