# include <stdio.h>
void Traverse(int array[], int size);

void main(){
    int arr[100] = {1, 2, 34, 5};
    Traverse(arr, 10);
}

void Traverse(int array[], int elements){
    printf("Array = [ ");
    for(int i=0; i<elements; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}