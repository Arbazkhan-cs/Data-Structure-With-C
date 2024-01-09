# include <stdio.h>
# include <stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *node1, *node2, *tail = 0;
    // node 1
    node1 = (struct node *) malloc(sizeof(struct node));
    node1->data = 5;
    head = tail = node1;
    node1->prev = tail;
    node1->next = head;

    // node 2
    node2 = (struct node *) malloc(sizeof(struct node));
    node2->data = 10;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node1;
    node1->prev = node2;
    tail = node2;

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

                newnode->prev = tail;
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                tail->next = head;
                printf("Insertion Begning Done");
                break;


            
            case 2:
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                newnode->next = head;
                newnode->prev = tail;
                tail->next = newnode;
                tail = newnode;
                head->prev = tail;
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
                    head->prev = tail;
                    tail->next = head;
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
                while(temp->next != head){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("%d\n", temp->data);
                break;


            case 5:
                choice = 0;
                break;


            default:
                printf("Invalid Input!!!");


        }
    } while(choice != 0);

}