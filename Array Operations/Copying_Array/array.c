# include <stdio.h>
# include <stdlib.h>
void array_copy(int arr_1[], int elements_1, int *arr_2, int size_2);
void display(int [], int elem);

void main(){
    int arr[10] = {5, 73, 23, 90}, arr_2[10];
    array_copy(arr, 4, &arr_2[0], 10);
    display(arr_2, 4);
}

void array_copy(int arr_1[], int elements_1, int *arr_2, int size_2){
    if(elements_1>size_2)
        exit(0);
    
    for(int i=0; i<elements_1; i++){
        *(arr_2+i) = arr_1[i];
    }
}

void display(int arr[], int elem){
    printf("Array = [ ");
    for(int i =0; i<elem; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}