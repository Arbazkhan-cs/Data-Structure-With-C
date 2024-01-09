# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *node1, *node2, *node3, *temp;
    node1 = (struct node *) malloc(sizeof(struct node));
    node2 = (struct node *) malloc(sizeof(struct node));
    node3 = (struct node *) malloc(sizeof(struct node));
    // data
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    // linking
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = 0;

    // display linked list
    temp = head;
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }


    // Reversing the linked list
    struct node *prevnode, *nextnode, *currentnode;
    prevnode = 0;
    nextnode = head;
    currentnode = head;
    while(nextnode != 0){ 
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
    free(currentnode);
    free(nextnode);
    // free(prevnode);  // we can't free it as we have assigned it's value to head.


    // display reverse linked list
    temp = head;
    printf("\n");
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    

}