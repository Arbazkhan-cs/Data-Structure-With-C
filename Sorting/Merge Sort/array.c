# include <stdio.h>
void mergeSort(int arr[], int low, int heigh);
void Merged(int arr[], int low, int mid, int heigh);
void display(int arr[], int size);

void main(){
    int arr[]={9, 1, 4, 14, 4, 15, 6}, n=7, low=0, heigh=n-1;

    display(arr, n);
    mergeSort(arr, low, heigh);
    display(arr, n);
}

void mergeSort(int arr[], int low, int heigh){
    if(low<heigh){
        int mid = low + (heigh-low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, heigh);
        Merged(arr, low, mid, heigh);
    }    
}

void Merged(int arr[], int low, int mid, int heigh){
    int arr2[100];

    int i, j, k;
    i = low;
    j = mid+1;
    k = low;

    while(i<=mid && j<=heigh){
        if(arr[i]>arr[j]){
            arr2[k++] = arr[j++];
        }
        else{
            arr2[k++] = arr[i++];
        }
    }

    while(i<=mid)
        arr2[k++] = arr[i++];
    
    while(j<=heigh)
        arr2[k++] = arr[j++];

    for(int i=low; i<=heigh; i++){
        arr[i] = arr2[i];
    }
}

void display(int arr[], int size){
    printf("Array = [");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}