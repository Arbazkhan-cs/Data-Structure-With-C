# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *newnode, *temp, *node1, *node2;
    node1 = (struct node *) malloc(sizeof(struct node));
    // First Node
    node1->data = 10;
    node1->next = 0;
    head = node1;

    // Second Node
    node2 = (struct node *) malloc(sizeof(struct node));
    node2->data = 12;
    node2->next = 0;
    node1->next = node2;

    // Deletion
    int choice = 1;
    do{
        printf("\n1). Insert New Node\n");
        printf("2). Delete Node From Begining\n");
        printf("3). Delete Node From End\n");
        printf("4). Delete Node From Middle\n");
        printf("5). Display Nodes\n");
        printf("6). Exit\n");
        printf("Enter The Choice[1/2/3/4/5/6]: ");
        scanf("%d", &choice);
        switch(choice){
            // Insertion
            case 1:
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter the data of new node: ");
                scanf("%d", &newnode->data);
                temp = head;
                while(temp->next != 0){
                    temp = temp->next;
                }
                newnode->next = 0;                
                temp->next = newnode;
                temp = head;
                printf("Insertion Done");
                break;
            

            // Deletion at the bigining
            case 2:
                temp = head;
                head = head->next;
                free(temp);
                printf("Deletion From The Begining Done");
                break;


            // Deletion at the end.
            case 3:
                temp = head;
                while(temp->next->next != 0){
                    temp = temp->next;
                }
                if(temp == head){
                    head = 0;
                    free(temp);
                } else{
                    free(temp->next);
                    temp->next = 0;
                }
                printf("Deletion From The End Done");
                break;


            // Deletion at the middle
            int possi, i;
            struct node *posinode;
            case 4:
                printf("Enter The Node Index which You Want To Delete: ");
                scanf("%d", &possi);
                
                temp = head;

                i = 1;
                while(i < possi - 1){
                    temp = temp->next;
                    i++;
                }
                if(possi == i){
                    head = head->next;
                    free(temp);
                } else{
                    posinode = temp->next;
                    temp->next = posinode->next;
                    free(posinode); 
                }
                printf("Deletion From The Possition Done");
                break;


            // Display
            case 5:
                temp = head;
                printf("Data: ");
                while(temp != 0){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }          
                break;


            // Exit
            case 6:
                choice = 0;
                break;


            default:
                printf("Invalid Value!!!\n");
        }

    } while(choice != 0);

}
