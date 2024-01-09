# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

void main(){
    struct node *node1, *newnode, *temp, *head = 0;

    // Creating First Node And Creating our fist liked list with it.
    node1 = (struct node *) malloc(sizeof(struct node));
    node1->data = 1;
    node1->next = 0;
    head = node1;

    int choice;
    do{
        newnode = (struct node *) malloc(sizeof(struct node));
        
        printf("\n1). Insertion At Begining\n");
        printf("2). Insertion At End\n");
        printf("3). Insertion At Middle\n");
        printf("4). Display Data\n");
        printf("5). Exit\n");
        printf("Chose[1/2/3/4/5]: ");
        scanf("%d", &choice);



        switch(choice){

            // Insertion At Begining
            case 1: 
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                newnode->next = head;
                head = newnode;
                break;
            



            // Insertion At The End
            case 2:
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);

                temp = head;
                while(temp->next != 0){
                    temp = temp->next;
                }
                newnode->next = 0;
                temp->next = newnode;
                temp = head;
                break;
            



            // Insertion At The Middle
            int possi;
            case 3:
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);
                printf("Enter The Possition: ");
                scanf("%d", &possi);

                if(possi == 0){
                    newnode->next = head;
                    head = newnode;
                }

                temp = head;
                while(--possi){
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
                break;
                


            // Linked List Display
            case 4:
                temp = head;
                printf("Data: ");
                while(temp != 0){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }          
                printf("\n");     
                break;



            case 5:
                printf("Ok Bye");
                break;


            default:
                printf("Invalid Input!!!");

        }

    } while(choice != 5);



}