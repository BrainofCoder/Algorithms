#include<stdio.h> // printf
#include<stdlib.h> // malloc

struct Node
{
    int data;
    struct Node *next, *previus;
};
push_front(struct Node **head, int v)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=v;
    new_node->next=*head;
    new_node->previus=NULL;
    if(*head!=NULL)
        (*head)->previus=new_node;
    *head=new_node;
    
}
push_back(struct Node **head, int v)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node)), *move=*head;
    new_node->data=v;
    new_node->next=NULL;
    new_node->previus=NULL;
    
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(move->next!=NULL)
        move=move->next;
    new_node->previus=move;
    move->next=new_node;
}
int main()
{
    struct Node *head=NULL;
    push_back(&head,5);
    push_back(&head,6);
    push_front(&head,9);
    printf("%d",head->data);
    printf(" %d",head->next->data);
    printf(" %d",head->next->next->data);
    printf("\n%d",head->next->next->data);
    printf(" %d",head->next->next->previus->data);
    printf(" %d",head->next->next->previus->previus->data);
    return 0;
}
