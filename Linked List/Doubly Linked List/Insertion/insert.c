# include <stdio.h>
# include <stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *node1, *node2;
    // node 1
    node1 = (struct node *) malloc(sizeof(struct node));
    node1->data = 5;
    node1->prev = 0;
    node1->next = 0;
    head = node1;

    // node 2
    node2 = (struct node *) malloc(sizeof(struct node));
    node2->data = 10;
    node2->prev = node1;
    node2->next = 0;
    node1->next = node2;

    int choice;
    do{
        struct node *newnode, *temp;
        newnode = (struct node *) malloc(sizeof(struct node));

        printf("\n1). Insertion In Begining\n");
        printf("2). Insertion In End\n");
        printf("3). Insertion In Middle\n");
        printf("4). Desplay Node\n");
        printf("5). Exit\n");
        printf("Enter Your Choice[1/2/3/4/5]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                newnode->prev = 0;
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                printf("Insertion Begning Done");
                break;


            
            case 2:
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                newnode->next = 0;
                temp = head;
                while(temp->next != 0){
                    temp = temp->next;
                }

                temp->next = newnode;
                newnode->prev = temp;
                printf("Insertion End Done");
                break;


            int pos, i;
            case 3:
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);
                printf("Enter The Possition Where You Want To insert: ");
                scanf("%d", &pos);

                temp = head;
                i = 1;
                while(i<pos-1){
                    temp = temp->next;
                    i++;
                }
                if(pos == i){
                    newnode->next = head;
                    head->prev = newnode;
                    head = newnode;
                } else {
                    newnode->prev = temp;
                    newnode->next = temp->next;
                    temp->next->prev= newnode;
                    temp->next = newnode;
                }
                printf("Insertion Middle Done");
                break;


            case 4:
                temp = head;
                while(temp != 0){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                break;


            case 5:
                choice = 0;
                break;


            default:
                printf("Invalid Input!!!");


        }
    } while(choice != 0);

}