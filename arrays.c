# include <stdio.h>
# include <stdlib.h>
void insertion(int *ptr, int n);
void deletion(int *ptr, int n);
void arrShow(int [], int n);

void main(){
    int n, choice;
    printf("Enter The Length Of The Array: ");
    scanf("%d", &n);

    int *arr;
    arr = (int *) malloc(n*sizeof(int));

    printf("Enter The numbers: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    do{
        printf("\n1). Insertion\n");
        printf("2). Deletion\n");
        printf("3), Exit\n");
        printf("Enter The Choices[1, 2, 3]:");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                insertion(&arr[0], n);
                arrShow(arr, n+1);
                printf("Done!!!\n");
                break;

            case 2:
                deletion(&arr[0], n);
                arrShow(arr, n);
                break;
        }
        
    }while(choice!=3);
    free(arr);
    arrShow(arr, n);
}


void arrShow(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

void deletion(int *ptr, int n){
    int num, val;
    printf("Enter The Number That You Want To Delete: ");
    scanf("%d", &num);

    for(int i=0, j=n; i<=j; i++, j--){
        if(*(ptr+i) == num){
            val = i;
            break;
        }
        else if(*(ptr+j) == num){
            val = j;
            break;
        }
    }

    for(int i=val; i<n-1; i++){
        *(ptr+i) = *(ptr+(i+1));
        for(int j=0; j<n; j++){
            printf("%d ", *(ptr+j));
        }
        printf("\n");
    }
    printf("\n");
}

void insertion(int *ptr, int n){
    int loc, num;
    printf("Enter The Number and it's index value where you want to insert: ");
    scanf("%d %d", &num, &loc);

    for(int i=n; i>=loc; i--){
        if(loc == i){
            *(ptr+loc) = num;
            break;
        }
        *(ptr+i) = *(ptr+(i-1));
    }
}