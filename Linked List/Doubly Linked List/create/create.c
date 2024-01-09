# include <stdlib.h>
# include <stdio.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *newnode, *head=0, *temp;
    int choice;
    do{
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter The Data: ");
        scanf("%d", &newnode->data);

        newnode->prev = 0;
        newnode->next = 0;
        if(head == 0){
            head = newnode;
            temp = newnode;
        } else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do You Want To Continue[1/0]: ");
        scanf("%d", &choice);
    } while(choice != 0);

    temp = head;
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}