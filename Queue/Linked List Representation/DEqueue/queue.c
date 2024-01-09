# include <stdio.h>
# include <stdlib.h>
struct queue{
    int data;
    struct queue *next;
};
struct queue *front = 0, *rear = 0;

void insertFront(int data){
    struct queue *newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data = data;
    
    if(front == 0){
        front = rear = newnode;
        newnode->next = front;
    }
    else{
        newnode->next = front;
        front = newnode;
        rear->next = front;
    }
}

void insertRear(int data){
    struct queue *newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data = data;
    
    if(front == 0){
        front = rear = newnode;
        newnode->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void deleteFront(){
    if(front == 0){
        printf("Underflow!!!\n");
    }
    else{
        struct queue *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void deleteRear(){
    if(front == 0){
        printf("Underflow!!!\n");
    }
    else{
        struct queue *temp = front;
        while(temp->next != rear){
            temp = temp->next;
        }
        rear = temp;
        temp = temp->next;
        free(temp);
        rear->next = front;
    }
}

void display(){
    struct queue *temp;
    temp = front;
    while(temp->next != front){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
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