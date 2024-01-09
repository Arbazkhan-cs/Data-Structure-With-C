# include <stdio.h>
void main(){
    int arr[10][10], col, row, isSparse=0;
    printf("Enter The Length Of Row of Sparse Matrix: ");
    scanf("%d", &row);
    printf("Enter The Length Of Column of Sparse Matrix: ");
    scanf("%d", &col);

    printf("Enter The Sparse Matrix:\n");
    for(int i = 0; i<row; i++){
        for(int j =0; j<col; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0)
                isSparse += 1;
        }
    }

    if(isSparse > (row*col)/2)
        printf("It is a Sparse Matrix\n\n");
    else
        printf("It is not a Sparse Matrix\n\n");

    printf("Your Data is:\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] != 0){
                printf("\nRow = %d\n", i);
                printf("Colums = %d\n", j);
                printf("Value = %d\n", arr[i][j]);
            }
        }
    }
}