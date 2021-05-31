#include<stdio.h>

void display(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    

}

void indexDeletion(int arr[], int size, int index) {


        for(int i = index; i < size -1; i++) {

            arr[i] = arr[i+1];

        }


}

int main() {

    int arr[5] = {1, 2, 6, 7, 9};
    int size = 5;
    int index = 3;
    display(arr, size);

    indexDeletion(arr, size, index);


    size--;
    display(arr, size);

    
    return 0;

}