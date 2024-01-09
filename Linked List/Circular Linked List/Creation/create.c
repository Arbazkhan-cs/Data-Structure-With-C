# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *temp;
    int choice = 1;
    while(choice){
        struct node *newnode;
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter The Data: ");
        scanf("%d", &newnode->data);
        newnode->next = head;

        if(head == 0){
            head = newnode;
            temp = newnode;
        } else{
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do You Want To Continue[1/0]: ");
        scanf("%d", &choice);
    }

    temp = head;
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}