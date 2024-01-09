# include <stdio.h>
# define n 10

void display(int arr[]);
// Insertion Sort
void main(){
    int arr[n] = {29, 47, 83, 13, 56, 32, 90, 10, 43, 11};

    display(arr);
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1] = arr[j];
            j--; 
        }

        arr[j+1] = temp;
    }
    display(arr);
}
void display(int arr[]){
    printf("Array = [ ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}