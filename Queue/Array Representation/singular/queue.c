# include <stdio.h>
#define N 5
int arr[N];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(rear == N-1){
        printf("Overflow!!!");
    }
    else{
        if(front == -1){
            front++;
        }
        rear++;
        arr[rear] = data;
        printf("Enqueue Data = %d\n", data);
    }
}

void dequeue(){
    if(front == -1){
        printf("Underflow!!!");
    }
    else{
        printf("Dequeue Data = %d\n", arr[front]);
        front++;
        if(front>rear){
            front = -1;
            rear = -1;
        }
    }
}
void peek(){
    if(front == -1){
        printf("Queue Is Empty!!!");
    }
    else{
        printf("Peek Value = %d\n", arr[rear]);
    }
}

void display(){
    if(front == -1){
        printf("Queue Is Empty!!!");
    }
    else{
        printf("Queue Value = [ ");
        for(int i = front; i<=rear; i++){
            printf("%d ", arr[i]);
        }
        printf("]\n");
    }
}

void main(){
    int choice = 1;
    while(choice){
        printf("\n1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Peek\n");
        printf("4). Display\n");
        printf("5). Exit\n");
        printf("Enter Choice[1/2/3/4/5]: ");
        scanf("%d", &choice);

        switch(choice){
            int data;
            case 1:
                printf("Enter The Data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                choice = 0;
                break;

            default: 
                printf("Invalid Choice!!! pls choose choice in [1/2/3/4/5]");
        }
    }
}
