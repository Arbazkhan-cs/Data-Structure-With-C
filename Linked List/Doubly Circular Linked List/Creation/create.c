# include <stdlib.h>
# include <stdio.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *newnode, *head=0, *tail;
    int choice;
    do{
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter The Data: ");
        scanf("%d", &newnode->data);


        if(head == 0){
            head = newnode;
            tail = newnode;
            newnode->prev = tail;
            newnode->next = head;
        } else{
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            tail = newnode;
            head->next = tail;
        }

        printf("Do You Want To Continue[1/0]: ");
        scanf("%d", &choice);
    } while(choice != 0);

    struct node *temp;
    temp = head;
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}