# include <stdio.h>
# include <stdlib.h>
void display(int array[], int elements);
void merge(int *array_1, int elements_1, int size_1,int array_2[], int elements_2);

void main(){
    int arr_1[100] = {1, 2, 3, 4};
    int arr_2[100] = {5, 6, 7, 8};

    merge(&arr_1[0], 4, 100, arr_2, 4);
    display(arr_1, 10);
}

void merge(int *arr_1, int elem_1, int size_1,int arr_2[], int elem_2){
    if(elem_1+elem_2 > size_1){
        printf("Not Enough Space In The First Array!!!\n");
        return;
    }
    
    for(int i=elem_1, j=0; j<elem_2; i++, j++){
        *(arr_1+i) = arr_2[j];
    }
}



void display(int array[], int elements){
    printf("Array = [ ");
    for(int i = 0; i<elements; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}