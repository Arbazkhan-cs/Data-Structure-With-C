# include <stdio.h>
void main(){
    int arr[10][10], col, row, isLowerTri=0;
    printf("Enter The Length Of Row of Upper Triangular Matrix: ");
    scanf("%d", &row);
    printf("Enter The Length Of Column of Upper Triangular Matrix: ");
    scanf("%d", &col);

    printf("Enter The Matrix:\n");
    for(int i = 0; i<row; i++){
        for(int j =0; j<col; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}