# include <stdio.h>
# include <stdlib.h>

struct queue{
    int data;
    struct queue *next;
};
struct queue *top = 0, *head = 0;

void enqueue(int data){
    struct queue *newnode;
    newnode = (struct queue *) malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->next = 0;
    if(head == 0){
        head = top = newnode;
    } 
    else{
        top->next = newnode;
        top = newnode;
    }
    printf("Enqueue Data = %d\n", top->data);
}

void dequeue(){
    if(head == 0){
        printf("Underflow!!!\n");
    }
    else{
        printf("Dequeue Data = %d\n", head->data);
        struct queue *temp = head;
        head = head->next;
        free(temp);
    }
}

void peek(){
    if(head == 0){
        printf("Queue Is Empty!!!\n");
    }
    else{
        printf("Peek Value = %d\n", top->data);
    }
}

void display(){
    if(head == 0){
        printf("Queue Is Empty!!!\n");
    }
    else{
        struct queue *temp = head;
        printf("Queue Data = [ ");
        while(temp != 0){
            printf("%d ", temp->data);
            temp = temp->next;
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
