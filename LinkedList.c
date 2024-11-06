#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void main()
{
    struct node *newnode,*current,*head=NULL;
    int i,n;
    printf("\nEnter the no.of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Node data: ");
        scanf("%d", &newnode->data);
        if(head==NULL){
            head=newnode;
            current=newnode;
        }
        else{
            current->next=newnode;
            current=newnode;
        }
    }
    current->next=NULL;
    for(current=head;current!=NULL;current=current->next)
    {
        printf("%d ",current->data);

    }
}