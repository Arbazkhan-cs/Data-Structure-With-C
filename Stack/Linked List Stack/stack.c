# include <stdio.h>
# include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *top = 0;

void push(int data){
    struct stack *newnode;
    newnode = (struct stack *) malloc(sizeof(struct stack));
    newnode->data = data;

    if(top == 0){
        top = newnode;
        newnode->next = 0;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
    printf("Pushed Data = %d\n", top->data);
}

void pop(){
    if(top == 0){
        printf("Underflow!!!\n");
    }
    else{
        printf("Poped Data = %d\n", top->data);
        struct stack *temp;
        temp = top;
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == 0){
        printf("Stack Is Empty!!!\n");
    }
    else{
        printf("Peek Value = %d\n", top->data);
    }
}

void display(){
    if(top == 0){
        printf("Stack Is Empty!!!\n");
    }
    else{
        struct stack *temp;
        temp = top;
        printf("Stack Data = [ ");
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
        printf("\n1). push\n");
        printf("2). pop\n");
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
                push(data);
                break;

            case 2:
                pop();
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
