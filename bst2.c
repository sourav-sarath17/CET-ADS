#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

void insert();
void delete();
void display();

void main(){
    int ch;
    while(1){
        printf("\nEnter choice-\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nChoice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: return;
            break;
            default: printf("\nInvalid choice");
            break;
        }
    }
}

struct node* insertion(struct node* root, struct node *newnode){
    if(root == NULL)
        root=newnode;
    else if(newnode->data > root->data)
        root->right = insertion(root->right, newnode);
    else
        root->left = insertion(root->left, newnode);
    return root;
}

void insert(){
    struct node *newnode;
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left = newnode->right=NULL;
    printf("\nEnter data:");
    scanf("%d",&data);
    newnode->data=data;
    root=insertion(root,newnode);

}
struct node* successor(struct node* node){
    node = node->right;
    while(node->right != NULL){
        node=node->left;
    }
    return node;
}

struct node *deletion(struct node* root,int key){
    struct node *temp;
    if(root == NULL)
        printf("\nTree empty");
    else if(key > root->data)
        root->right= deletion(root->right,key);
    else if(key < root->data)
        root->left= deletion(root->left,key);
    else{
        if(root->left == NULL){
            temp= root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            temp= root->left;
            free(root);
            return temp;
        }
        else{
            struct node *succ=successor(root);
            root->data=succ->data;
            root->right=deletion(root->right,succ->data);
        }
    }
    return root;
}

void delete(){
    printf("\nEnter the value to be deleted:");
    int key;
    scanf("%d",&key);
    deletion(root,key);
}


void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
}

void display(){
    int ch;
    printf("\nEnter 1-Inorder\n2-Preorder\n3-Postorder");
    printf("\nEnter choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:inorder(root);
        break;
        case 2: preorder(root);
        break;
        case 3: postorder(root);
        break;
 
    }
}