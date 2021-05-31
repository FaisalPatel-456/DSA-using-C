#include<stdio.h>

int arr[10];
int n, i, j, ele, pos;

void insert() {
    pos = pos - 1;
    for(i = n; i <= pos; i--) {

        arr[i] = arr[i-1];

    }

    arr[pos] = ele;

}

int main() {

    printf("Enter size of array ");
    scanf("%d", &n);

    for(i = 0; i<n; i++){

        scanf("%d", &arr[i]);

    }

    printf("Enter element to insert ");
    scanf("%d", &ele);

    printf("Enter position to insert ");
    scanf("%d", &pos);

    insert();

    for(j = 0; j<= n; j++){

        printf("%d\t", arr[j]);

    }

}
