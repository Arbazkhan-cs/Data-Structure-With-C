# include <stdio.h>
# include <stdlib.h>
struct queue{
    int data;
    struct node *next;
};
struct queue *front = 0, *rear = 0;

void enqueue(int data){
    struct queue *newnode;
    newnode = (struct queue *) malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->next = 0;
    if(front == 0){
        front = rear = newnode;
        newnode->next = front;
    }else{
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
    printf("Enqueue Data = %d\n", newnode->data);
}

void dequeue(){
    if(front == 0){
        printf("Underflow!!!\n");
    }
    else{
        printf("Dequeue Data = %d\n", front->data);
        struct queue *temp = front;
        if(front->next == front){
            front = rear = 0;
        }else{
            front = front->next;
            rear->next = front;
        }
        free(temp); 
    }
}

void peek(){
    if(front == 0){
        printf("Queue is Empty\n");
    }
    else{
        printf("Peek Data = %d\n", front->data);
    }
}

void display(){
    if(front == 0){
        printf("Queue is Empty\n");
    }else{
        struct queue *temp = front;
        while(temp->next != front){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
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
