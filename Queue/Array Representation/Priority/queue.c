# include <stdio.h>
#define N 5
int queue[N];
int priQueue[N];
int idx = -1;


void enqueue(int data, int pri){
    if(idx == N-1){
        printf("Overflow!!!\n");
    }
    else{
        if(idx == -1){
            idx++;
            queue[idx] = data;
            priQueue[idx] = pri;
        }
        else{
            idx++;
            for(int i = idx-1; i>=0; i--){
                if(priQueue[i] >= pri){
                    queue[i+1] = queue[i];
                    priQueue[i+1] = priQueue[i];
                    if(i == 0){
                        queue[i] = data;
                        priQueue[i] = pri;
                    }
                }
                
                else{
                    queue[i+1] = data;
                    priQueue[i+1] = pri;
                    break;
                }
            }
        }
        printf("Data Inserted\n");
    }
}

void dequeue(){
    if(idx == -1){
        printf("Underflow!!!\n");
    }
    else{
        idx--;
    }
}

void peek(){
    printf("Peek: data = %d, Priority = %d\n", queue[idx], priQueue[idx]);
}

void display(){
    for(int i = 0; i<=idx; i++){
        printf("data = %d, priority = %d\n", queue[i], priQueue[i]);
    }
}

void main(){
    int choice = 1;
    while(choice){
        printf("\n1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Peek\n");
        printf("4). Display\n");
        printf("5). Exit\n");
        printf("Enter Choice[1/2/3/4/5]: ");
        scanf("%d", &choice);

        switch(choice){
            int data, pri;
            case 1:
                printf("Enter The Data: ");
                scanf("%d", &data);
                printf("Enter The Priority: ");
                scanf("%d", &pri);
                enqueue(data, pri);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                choice = 0;
                break;

            default: 
                printf("Invalid Choice!!! pls choose choice in [1/2/3/4/5]");
        }
    }
}