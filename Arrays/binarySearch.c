#include<stdio.h>

int binarySearch(int arr[], int size, int element) {

    int mid, high, low;
    low = 0;
    high = size -1;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if(arr[mid] == element) {
            return mid;
        }
        if(arr[mid] < element) {

            low = mid + 1;

        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
    

}

int main() {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 44};
    int size = sizeof(arr)/sizeof(int);
    int element = 9;
    int searchIndex = binarySearch(arr, size, element);

    if(searchIndex == -1) {
        printf("%d found not found", element);
    } else
    {
        printf("%d found at index %d", element, searchIndex);
    }
    return 0;

}