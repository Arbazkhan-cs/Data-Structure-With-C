# include <stdio.h>
# include <stdlib.h>

struct priQueue{
    int data;
    int priority;
    struct priQueue *next;
};
struct priQueue *front = 0;

void enqueue(int data, int priority){
    struct priQueue *newnode;
    newnode = (struct priQueue *) malloc(sizeof(struct priQueue));
    newnode->data = data;
    newnode->priority = priority;

    if(front == 0 || front->priority >= priority){
        newnode->next = front;
        front = newnode;
    }
    else{
        struct priQueue *temp;
        temp = front;
        while(temp->next != 0 && temp->next->priority <= priority){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void dequeue(){
    if(front == 0){
        printf("Underflow!!!\n");
    }
    else{
        struct priQueue *temp;
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){
    struct priQueue *temp = front;
    if(front == 0){
        printf("Queue is empty\n");
    }
    else{
        while(temp != 0){
            printf("Data: %d Priority: %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
        free(temp);
    }
}

void main(){
    int choice = 1;
    while(choice){
        printf("\n1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Display\n");
        printf("4). Exit\n");
        printf("Enter Choice[1/2/3/4]: ");
        scanf("%d", &choice);

        switch(choice){
            int data, pri;
            case 1:
                printf("Enter The Data: ");
                scanf("%d", &data);
                printf("Enter The Priority: ");
                scanf("%d", &pri);
                enqueue(data, pri);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                choice = 0;
                break;

            default: 
                printf("Invalid Choice!!! pls choose choice in [1/2/3/4/5]");
        }
    }
}