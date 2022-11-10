#include "BinarySearchTree.h"

int add(TreeNode **root, void *element, TreeComparator f){
    if(*root == NULL){
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    if(newnode == NULL) return 0;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->element = element;
    *root = newnode;
    return 1;
 }
    int compvalue = f(element, (*root)->element);
        if(compvalue > 0){
        return add(&(*root)->right, element, f);
        }
        else if(compvalue < 0 ){
            return add(&(*root)->left, element, f);
        }
        else{
            return -1;
        }
}
    
int find(TreeNode *root, void *key, TreeComparator f, void **element){
    if (root == NULL)return 0;
    int compvalue = f(key, root->element);
    if(compvalue == 0){
        *element = root->element;
        return 1;
    }
    if(compvalue > 0){
        return find(root->right, key, f, element);
        return find(root->left, key, f, element);
    }   
}

void in_order(TreeNode *root, printNode print){

}

void pre_order(TreeNode *root, printNode print){

}

void post_order(TreeNode *root, printNode print){

}

int removeTreeNode(TreeNode **root, void *key, TreeComparator f){
    if(*root == NULL){
        return 0;
    }
    int compvalue = f(key, (*root)->element);
    if(compvalue < 0){
    removeTreeNode(&(*root)->left, key, f);
    }
    else if(compvalue > 0){
    removeTreeNode(&(*root)->right, key, f);
    }
    else {
        TreeNode *aux = *root;
        if((*root)->left == NULL && (*root)->right == NULL){
            free(aux);
            *root = NULL;
        }
        }

int height (TreeNode *root){

}

void destroy (TreeNode **root){

}