# include <stdio.h>
# define n 10

void swap(int *, int *);
void show(int *ptr);

// Buble Sort
void main(){
    int arr[n] = {10, 20, 30, 75, 42, 94, 26, 49, 98, 100}, count = 1;
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);

            }
        }
        printf("%d). ", count++);
        show(&arr[0]);
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