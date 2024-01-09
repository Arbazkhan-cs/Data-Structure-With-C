# include <stdio.h>
# include <stdlib.h>
struct tree{
    int data;
    struct tree *lchild, *rchild;
};
struct tree *root = 0;

struct tree *create(){
    int x;
    struct tree *newnode;
    newnode=(struct tree*)malloc(sizeof(struct tree));
    printf("Enter the value of node: ");
    scanf("%d", &x);
    if(x == -1){
        return 0;
    }
    newnode->data = x;

    printf("enter the left child of %d:\n", x);
    newnode->lchild = create();
    printf("enter the right child of %d:\n", x );
    newnode->rchild = create();
    return newnode;
}


void preorder(struct tree *p){
    if(p == 0){
        return;
    }
    printf("%d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}
void main(){
    root = create();
    preorder(root);
}