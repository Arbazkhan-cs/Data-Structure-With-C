# include <stdio.h>
# include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head = 0, *tail;
int getLength(){
    struct node *temp;
    temp = head;
    int count = 0;

    while(temp->next != head){
        count++;
        temp = temp->next;
    }

    return count;
}

void main(){
    struct node  *node1, *node2;
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
        printf("\n1). Add A Node\n");
        printf("2). Deletion At The Begin\n");
        printf("3). Deletion At The End\n");
        printf("4). Deletion At The Middle\n");
        printf("5). Display\n");
        printf("6). Exit\n");
        printf("Enter The choice[1/2/3/4/5/6]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                newnode = (struct node *) malloc(sizeof(struct node));
                printf("Enter The Data: ");
                scanf("%d", &newnode->data);
                tail->next = newnode;
                tail = newnode;
                tail->next = head;
                break;

            case 2:
                if(head == 0){
                    printf("Linked List Is Empty!!!");
                    break;
                }
                temp = head;
                head = head->next;
                tail->next = head;
                free(temp);
                break;

            case 3:
                if(head == 0){
                    printf("Linked List Is Empty!!!");
                    break;
                }

                while(tail->next->next != head){
                    tail = tail->next;
                }
                free(tail->next);
                tail->next = head;
                break;


            int p, size;
            case 4:
                if(head == 0){
                    printf("Linked List Is Empty!!!");
                    break;
                }
                printf("Enter The Possition: ");
                scanf("%d", &p);

                size = getLength();
                if(p > size || p < 1){
                    printf("Invalid Position!!!");  
                    break;
                }

                
                temp = head;
                while(--p){
                    temp = temp->next;
                }
                struct node *next;
                next = temp->next;
                temp->next = next->next;
                free(next);
                break;
                

            case 5:
                if(head == 0){
                    printf("Linked List Is Empty!!!");
                    break;
                }
                temp = head;
                while(temp->next != head){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("%d ", temp->data);

                break;

            case 6:
                choice = 0;
                break;

            default:
                printf("Invalid Possition!!!");
                break;
        }
    }
}
