# include <stdio.h> 
# include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *node1, *node2, *node3, *tail;
    // node 1
    node1 = (struct node *) malloc(sizeof(struct node));
    node1->data = 5;
    head = tail = node1;
    node1->prev = tail;
    node1->next = head;

    // node 2
    node2 = (struct node *) malloc(sizeof(struct node));
    node2->data = 10;
    node2->prev = node1;
    node1->next = node2;
    tail = node2;
    tail->next = head;
    head->prev = tail;

    // node 3
    node3 = (struct node *) malloc(sizeof(struct node));
    node3->data = 8;
    node3->prev = node2;
    node2->next = node3;
    tail = node3;
    tail->next = head;
    head->prev = tail;


    int choice;
    do{
        printf("1). Insert Data\n");
        printf("2). Delete From The Begin\n");
        printf("3). Delete From The End\n");
        printf("4). Delete From Middle\n");
        printf("5). Display Node\n");
        printf("6). Exit\n");
        printf("Enter The Choice[1/2/3/4/5/6]: ");
        scanf("%d", &choice);

        switch(choice){
            // Insertion
            struct node *newnode, *temp;
            case 1:
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                newnode->prev = tail;
                tail->next = newnode;
                tail = newnode;
                tail->next = head;
                head->prev = tail;
                printf("Insertion Done\n");
                break;

            
            // Deletion Form  The Begining
            case 2:
                temp = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;
                free(temp);
                printf("Deletion from the begin done\n");
                break;


            // Deletion From The End
            case 3:
                if(tail == head){
                    temp = head;
                    head = tail = 0;
                    free(temp);
                } else{
                    temp = tail;
                    tail = tail->prev;
                    free(temp);
                    tail->next = head;
                    head->prev = tail;
                }
                printf("Deletion from the end done\n");
                break;

            

            // Deletion From The Specific Possition
            int pos, i;
            case 4:
                printf("Enter The Possition Where You Want To Delete: ");
                scanf("%d", &pos);

                temp = head;
                i=1;
                while(i<pos){
                    temp = temp->next;
                    i++;
                }
                if(temp == head){
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                    free(temp);

                } else if(temp->next == head){
                    tail = tail->prev;
                    free(temp);
                    tail->next = head;
                    head->prev = tail;

                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                printf("Deletion From The Middle Done\n");
                break;


            // display
            case 5:
                temp = head;
                while(temp->next != head){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("%d\n", temp->data);
                break;


            // exit
            case 6:
                choice = 0;
                break;
            
            default:
                printf("INVALID INPUT!!!");
        }

    } while(choice != 0);

}