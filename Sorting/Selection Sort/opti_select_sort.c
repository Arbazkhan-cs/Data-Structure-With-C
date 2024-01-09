# include <stdio.h>
# define n 10
void swap(int *, int *);
void show(int *);

// Optimized Selection Sort
void main(){
    int arr[n] = {10, 20, 30, 75, 42, 94, 26, 49, 98, 100}, min=0, isSort = 0, count = 1;
    show(&arr[0]);
    for(int i=0; i<n-1; i++){
        isSort = i+1;
        min = i;
        for(int j = i+1; j<n; j++){
            isSort += arr[j-1] <= arr[j];
            if(arr[min] > arr[j]){
                min = j;
            }
        }

        if(min != i){
            swap(&arr[i], &arr[min]);
        }
        if(isSort == n)
            break;

    }
    show(&arr[0]);
}

void swap(int *val1, int *val2){
    int temp = *(val1);
    *(val1) = *(val2);
    *(val2) = temp;
}
void show(int *ptr){
    printf("Array = [ ");
    for(int i=0; i<n; i++){
        printf("%d ", *(ptr+i));
    }
    printf("]\n");
}