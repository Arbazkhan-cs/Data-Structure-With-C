# include <stdio.h>
# define n 10
void main(){
    int arr[n]={27, 87, 32, 67, 23, 89, 10, 89, 55, 35}, search;

    printf("\nArray = [ ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");


    printf("Enter the number that you want to search: ");
    scanf("%d", &search);

    for(int i=0; i<n; i++){
        if(search == arr[i]){
            printf("The number is at Index Number: %d", i);
            break;
        }   
        else if(i==(n-1)){
            printf("The number you inputed is not in the array!!!");
            break;
        }
    }
}