# include <stdio.h>
# include <stdlib.h>
struct tree{
    int data;
    struct tree *lchild, *rchild;
};
struct tree *root = NULL;

// recusively insertion in BST
struct tree *insert(struct tree *p, int key){
    if(p == NULL){
        p = (struct tree *) malloc(sizeof(struct tree));
        p->data=key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    else{
        if(p->data > key){
            p->lchild = insert(p->lchild, key);
        }
        else{
            p->rchild = insert(p->rchild, key);
        }
    }
}
void preorder(struct tree *parrent){
    if(parrent == NULL){
        return;
    }
    printf("%d ", parrent->data);
    preorder(parrent->lchild);
    preorder(parrent->rchild);
}

void main(){
    root = insert(root, 50); // inserting the first node of a binary search
    insert(root, 20);
    insert(root, 30);
    insert(root, 10);
    preorder(root);
}