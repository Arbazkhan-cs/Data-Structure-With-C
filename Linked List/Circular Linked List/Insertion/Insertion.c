# include <stdio.h>
# include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void main(){
    struct node *head = 0, *node1, *node2, *tail;
    // first node
    node1 = (struct  node *) malloc(sizeof(struct node));
    node1->data = 10;
    head = node1;
    node1->next = head;
    tail = node1;

    // second node
    node2 = (struct  node *) malloc(sizeof(struct node));
    node2->data = 10;
    node1->next = node2;
    node2->next = head;
    tail = node2;


    int choice = 1;
    while(choice){
        struct node *newnode, *temp;
        printf("\n1). Insertion At The Begin\n");
        printf("2). Insertion At The End\n");
        printf("3). Insertion At The Middle\n");
        printf("4). Display\n");
        printf("5). Exit\n");
        printf("Enter The choice[1/2/3/4/5]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d", &newnode->data);
                newnode->next = head;
                head = newnode;
                tail->next = head;
                break;
            
            case 2:
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d", &newnode->data);
                
                // temp = head;
                // while(temp->next != head){
                //     temp = temp->next;
                // }
                // temp->next = newnode;
                // newnode->next = head;

                tail->next = newnode;
                tail = newnode;
                tail->next = head;
                break;

            int p;
            case 3:
                printf("Enter The Possition: ");
                scanf("%d", &p);
                
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d", &newnode->data);
    
                if(p == 0){
                    newnode->next = head;
                    head = newnode;
                    tail->next = head;
                    break;
                }

                temp = head;
                while(--p){
                    temp = temp->next;
                }
            
                newnode->next = temp->next;
                temp->next = newnode;
                break;

            case 4:
                temp = head;
                if(head == 0){
                    printf("Linked List Is Empty");
                    break;
                }
                do{
                    printf("%d ", temp->data);
                    temp = temp->next;
                }while(temp != head);
                break;

            case 5:
                choice = 0;
                break;
            
            default:
                printf("Invalid input !!!");
        }

    }
}