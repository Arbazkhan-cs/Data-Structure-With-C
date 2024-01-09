# include <stdio.h>
# include <stdlib.h>
#define N 5
int arr[N];
int front = -1;
int rear = -1;

void insertFront(int data){
    if((front == 0 && rear == N-1) || front == rear+1){
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        arr[front] = data;
    }
    else if(front == 0){
        front = N-1;
        arr[front] = data;
    }
    else{
        front--;
        arr[front] = data;
    }
}
void insertRear(int data){
    if((front == 0 && rear == N-1) || front == rear+1){
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        arr[rear] = data;
    }
    else if(rear == N-1){
        rear = 0;
        arr[rear] = data;
    }
    else{
        rear++;
        arr[rear] = data;
    }
}
void deleteFront(){
    if(front == -1){
        printf("Underflow\n");
    }
    else if(front == rear){
        printf("Deleted Data = %d\n", arr[front]);
        front = rear = -1;
    }
    else if(front == N-1){
        printf("Deleted Data = %d\n", arr[front]);
        front = 0;
    }
    else{
        printf("Deleted Data = %d\n", arr[front]);
        front++;
    }
}
void deleteRear(){
    if(front == -1){
        printf("Underflow\n");
    }
    else if(front == rear){
        printf("Deleted Data = %d\n", arr[rear]);
        front = rear = -1;
    }
    else if(rear == 0){
        printf("Deleted Data = %d\n", arr[rear]);
        rear = N-1;
    }
    else{
        printf("Deleted Data = %d\n", arr[rear]);
        rear--;
    }
}
void display(){
    int i = front;
    if(front == -1){
        printf("Queue is Empty\n");
    }
    else{
        while(i != rear){
            printf("%d ", arr[i]);
            i = (i+1)%N;
        }
        printf("%d\n", arr[i]);
    }
}
void main(){
    int ch, data;
    do{
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1: 
                printf("Enter The Data: ");
                scanf("%d", &data);
                insertFront(data);
                break;

            case 2: 
                printf("Enter The Data: ");
                scanf("%d", &data);
                insertRear(data);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                ch = 0;
                break;

            default:
                printf("Inavlid Input!!!\n");
        }

    } while(ch);
}