#include<stdio.h>

int linearSearch(int arr[], int size, int element) {

    for(int i = 0; i < size; i++) {

        if(arr[i] == element) {

            return i;

        }

    }

    return -1;

}

int main() {

    int arr[] = {1, 5, 3, 4, 7, 6, 2, 8, 9, 0};
    int size = sizeof(arr)/sizeof(int);
    int element = 10;
    int searchIndex = linearSearch(arr, size, element);

    if(searchIndex == -1) {
        printf("%d found not found", element);
    } else
    {
        printf("%d found at index %d", element, searchIndex);
    }
    
    return 0;

}