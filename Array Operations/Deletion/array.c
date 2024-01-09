# include <stdio.h>
void Traversal(int array[], int size);
void deletion(int array[], int size, int elements, int del_index);

void main(){
    int arr[100] = {1, 2, 34, 5};
    Traversal(arr, 10);
    deletion(arr, 100, 4, 2);
    Traversal(arr, 10);
}

void deletion(int array[], int size, int elements, int del_index){
    if(elements <= del_index){
        printf("Invalid Index Number!!!\n");
        return;
    }    

    for(int i=0; i<elements; i++){
        if(i>=del_index){
            array[i] = array[i+1];
        }
    }
}


void Traversal(int array[], int elements){
    printf("Array = [ ");
    for(int i=0; i<elements; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}