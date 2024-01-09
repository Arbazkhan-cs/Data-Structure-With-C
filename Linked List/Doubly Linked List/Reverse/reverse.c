# include <stdio.h>
# include <stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *head=0, *temp, *node1, *node2, *node3;
    // node 1
    node1 = (struct node *) malloc(sizeof(struct node));
    node1->prev = 0;
    node1->data = 1;
    node1->next = 0;
    head = node1;

    // node 2
    node2 = (struct node *) malloc(sizeof(struct node));
    node2->prev = node1;
    node2->data = 2;
    node2->next = 0;
    node1->next = node2;
    
    // node 3
    node3 = (struct node *) malloc(sizeof(struct node));
    node3->prev = node2;
    node3->data = 3;
    node3->next = 0;
    node2->next = node3;


    // previous linked list
    temp = head;
    while(temp != 0 && head != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");


    // reverse of linked list======================================================================
    // Checking is liked list emty or has only one element
    if(head == 0 || head->next == 0){
        printf("Require Atlest 2 nodes for reverse.\n");
    }

    // If liked list have atlest 2 elements that this else will work and reverse the liked list
    else{
        struct node *prevnode, *nextnode, *currentnode;

        currentnode = head;                 // Putting current as the first node
        while(currentnode != 0){
            nextnode = currentnode->next;   // Now Putting nextnode to the next node of the current node
            prevnode = currentnode->prev;   // Now Putting prevnode to the previous node of the current node
            currentnode->next = prevnode;   // Now changing the current->next to prevnode address
            currentnode->prev = nextnode;   // now changing the current->prev to nextnode address
            currentnode = nextnode;      // last but not the least, we are putting current node to next node
        }
        head = prevnode->prev;
        free(currentnode);
        free(nextnode);
    }


    // reversed linked list
    temp = head;
    while(temp != 0 && head != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}