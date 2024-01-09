# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void main(){
    struct node *newnode, *temp, *head = 0;
    int choice = 0;

    do{
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter The Data: ");
        scanf("%d", &newnode->data);

        newnode->next = 0;
        if(head == 0){
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do You Want To continue(1/0): ");
        scanf("%d", &choice);

    } while(choice != 0);

    temp = head;
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }

}