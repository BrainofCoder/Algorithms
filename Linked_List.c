#include<stdio.h> // printf
#include<stdlib.h> // malloc

struct Node
{
    int data;
    struct Node *next;
};
push_front(struct Node **head, int v)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=v;
    new_node->next=*head;
    *head=new_node;
}
push_back(struct Node **head, int v)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node)), *move=*head;
    new_node->data=v;
    new_node->next=NULL;
    
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(move->next!=NULL)
        move=move->next;
    move->next=new_node;
}
void search(struct Node **head,int dato)
{
    struct Node *move = *head, *target, *prev=NULL;
    int token=1;
    if(move==NULL)
        return;
    while(move!=NULL)
    {
        if(move->data==dato)
        {
            token=0;
            break;
        }
        prev=move;
        move=move->next;
    }
    if(token)
        return;
    if(prev!=NULL)
    {
        prev->next=move->next;
        move->next=*head;
        *head=move;
    }
    target=prev=move=NULL;
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
    return 0;
}
