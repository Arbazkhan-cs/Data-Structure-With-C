# include <stdio.h>
# define N 5
int arr[N];
int front = -1;
int rear = -1;

void enqueue(int data){
    if((rear+1)%N == front){
        printf("Overflow!!!");
    }
    else{
        if(front == -1){
            front = (front+1)%N;
        }
        rear = (rear+1)%N;
        arr[rear] = data;
        printf("Enqueue Data = %d\n", arr[rear]);
    }
}

void dequeue(){
    if(front == -1){
        printf("Underflow!!!");
    }
    else{
        printf("Dequeue Data %d\n", arr[front]);
        front = (front+1)%N;
        if(front == rear){
            front = -1;
            rear = -1;
        }
    }
}

void peek(){
    if(front == -1){
        printf("Queue is Empty!!!");
    }    
    else{
        printf("Peek Data = %d\n", arr[front]);
    }
}

void frontPos(){
    if(front == -1){
        printf("Front Possition = %d\n", front);
    }
    else{
        printf("Front Possition = %d\n", arr[front]);
    }
}
void rearPos(){
    if(front == -1){
        printf("Rear Possition = %d\n", rear);        
    }
    else{
        printf("Rear Possition = %d\n", arr[rear]);
    }
}

void display(){
    if(front == -1){
        printf("Queue is Empty!!!");
    }
    else{
        frontPos();
        rearPos();
        printf("Queue Data : ");
        for(int i = front; i<=rear || i>=rear; i = (i+1)%N){
            printf("%d ", arr[i]);
            if(i == rear){
                break;
            }
        }
        printf("\n");
    }
}
void main(){
    int choice = 1;
    while(choice){
        printf("\n1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Font Possition\n");
        printf("4). Rear Possition\n");
        printf("5). Peek\n");
        printf("6). Display\n");
        printf("7). Exit\n");
        printf("Enter Choice[1/2/3/4/5/6/7]: ");
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
                frontPos();
                break;

            case 4:
                rearPos();
                break;

            case 5:
                peek();
                break;

            case 6:
                display();
                break;

            case 7:
                choice = 0;
                break;

            default: 
                printf("Invalid Choice!!! pls choose choice in [1/2/3/4/5]");
        }
    }
}
