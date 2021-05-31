#include<stdio.h>

void display(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    

}

int indexInsertion(int arr[], int size, int element,int capacity, int index) {

    if(size >= capacity) {

        return -1;

    } else {

        for(int i = size -1; i >= index; i--) {

            arr[i+1] = arr[i];

        }
        arr[index] = element;
        return 1;
    }

}

int main() {

    int arr[5] = {1, 2, 6, 7, 9};
    int size = 5;
    int index = 3;
    int success;
    int element = 45;
    display(arr, size);

    success = indexInsertion(arr, size, element, 5, index);

    if(success == 1) {

        size++;
        display(arr, size);

    } else
    {
        printf("Insertion failed");
    } 
    
    return 0;

}