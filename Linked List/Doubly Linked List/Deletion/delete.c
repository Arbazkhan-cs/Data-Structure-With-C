# include <stdio.h> 
# include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *node1, *node2, *node3, *temp;
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

    // node 3
    node3 = (struct node *) malloc(sizeof(struct node));
    node3->data = 8;
    node3->prev = node2;
    node3->next = 0;
    node2->next = node3;


    int choice;
    do{
        printf("\n1). Insert Data\n");
        printf("2). Delete From The Begin\n");
        printf("3). Delete From The End\n");
        printf("4). Delete From Middle\n");
        printf("5). Display Node\n");
        printf("6). Exit\n");
        printf("Enter The Choice[1/2/3/4/5/6]: ");
        scanf("%d", &choice);

        switch(choice){
            // Insertion
            struct node *newnode;
            case 1:
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                newnode->next = 0;
                temp = head;
                while(temp->next != 0){
                    temp = temp->next;
                }
                temp->next = newnode;
                newnode->prev = temp;
                printf("Insertion Done");
                break;

            
            // Deletion Form  The Begining
            case 2:
                temp = head;
                head = head->next;
                head->prev = 0;
                free(temp);
                printf("Deletion from the begin done");
                break;


            // Deletion From The End
            case 3:
                temp = head;
                while(temp->next != 0){
                    temp = temp->next;
                }
                if(temp == head){
                    head = 0;
                    free(temp);
                } else{
                    temp->prev->next = 0;
                    free(temp);
                }
                printf("Deletion from the end done");
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
                    head->prev = 0;
                    free(temp);

                } else if(temp->next == 0){
                    temp->prev->next = 0;
                    free(temp);

                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                printf("Deletion From The Middle Done");
                break;


            // display
            case 5:
                temp = head;
                while(temp != 0){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
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