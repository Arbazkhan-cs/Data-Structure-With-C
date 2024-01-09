# include <stdio.h>
# define N 5

int arr[N];
int top = -1;

void push(int data){
    if(top == N){
        printf("Overflow");
    } 
    else{
        top++;
        arr[top] = data;
    }
}
void pop(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        printf("Poped = %d\n", arr[top]);
        top--;
    }
}
void showStackData(){
    printf("Stack Data = ");
    for(int i = top; i>=0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    push(10);
    push(11);
    push(12);
    showStackData();
    pop();
    showStackData();
}
