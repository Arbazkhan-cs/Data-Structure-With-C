# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
struct tree{
    int data;
    struct tree *left, *right;
};
struct tree *root = NULL;

void insert(int data){
    struct tree *node;
    node = (struct tree *) malloc(sizeof(struct tree));
    node->data = data;
    node->left = node->right = NULL;

    if(root == NULL){
        root = node;
    }else{
        struct tree *curr, *p;
        curr = root;

        while(curr){
            p = curr;
            if(node->data > curr->data){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }

        if(node->data > p->data){
            p->right = node;
        }else{
            p->left = node;
        }
    }
}

void preorder(struct tree *parrent){
    if(parrent == NULL){
        return;
    }
    printf("%d ", parrent->data);
    preorder(parrent->left);
    preorder(parrent->right);
}

void postorder(struct tree *parrent){
    if(parrent == NULL){
        return;
    }
    postorder(parrent->left);
    postorder(parrent->right);
    printf("%d ",parrent->data);
}

void inorder(struct tree *parrent){
    if(parrent == NULL){
        return;
    }
    inorder(parrent->left);
    printf("%d ", parrent->data);
    inorder(parrent->right);
}

void main(){
    insert(5);
    insert(6);
    insert(4);
    
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
}
