# include <stdio.h>
# define n 10
void main(){
    int arr[n]={10, 23, 26, 39, 45, 51, 57, 69, 83, 92}, search;

    printf("\nArray = [ ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");


    printf("Enter the number that you want to search: ");
    scanf("%d", &search);

    int low=0, heigh=n-1, mid;
    while(1){
        mid = (low+heigh)/2;
        // printf("mid = %d\n", mid); // For Debugging
        // printf("low = %d\n", low);
        // printf("heigh = %d\n\n", heigh);
        if(low>heigh){
            printf("The number you want to find is not in the array!!!\n");
            break;
        }
        else if(search == arr[mid]){
            printf("The number is at Index Number: %d", mid);
            break;
        }
        else if(search < arr[mid])
            heigh = mid - 1;

        else if(search > arr[mid])
            low = mid + 1;
    }
}