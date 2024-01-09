# include <stdio.h>
# define n 10

void swap(int *, int *);
void show(int *ptr);

// Optimized Buble Sort
void main(){
    int arr[n] = {40, 10, 30, 25, 42, 94, 26, 49, 98, 100}, isSort = 0, count = 1;
    
    show(&arr[0]);
    for(int i=0; i<n-1; i++){
        isSort = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                isSort = 1;
            }
        }

        if(isSort == 0)
            break;
    }
    show(&arr[0]);
}

void swap(int *n1, int *n2){
    int temp = *(n1);
    *(n1) = *(n2);
    *(n2) = temp;
}

void show(int *ptr){
    printf("Array = [ ");
    for(int i=0; i<n; i++){
        printf("%d ", *(ptr + i));
    }
    printf("]\n");
}