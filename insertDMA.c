# include <stdio.h>
# include <stdlib.h>

void main(){
    int n;
    printf("Enter The Length Of The Array: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n*sizeof(int));
    printf("Enter The numbers: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int loc, num;
    printf("Enter The Number and it's index value where you want to insert: ");
    scanf("%d %d", &num, &loc);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    arr = (int *) realloc(arr, sizeof(int)*(n+1));

    for(int i=n; i>=loc; i--){
        if(loc == i){
            arr[loc] = num;
            break;
        }
        arr[i] = arr[i-1];
    }

    for(int i=0; i<=n; i++){
        printf("%d ", arr[i]);
    }
}