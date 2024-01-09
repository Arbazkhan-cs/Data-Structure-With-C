# include <stdio.h>
void Traversal(int array[], int size);
void insertion(int array[], int size, int elements,int num, int index);

void main(){
    int arr[100] = {1, 2, 34, 5};
    Traversal(arr, 10);
    insertion(arr, 100, 4, 10, 3);
    Traversal(arr, 10);
}

void insertion(int array[], int size, int elements, int num, int index){
    if(elements==size)
        return;


    for(int i = elements-1; i>=0; i--){
        array[i+1] = array[i];

        if(i == index){
            array[index] = num;
            break;
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