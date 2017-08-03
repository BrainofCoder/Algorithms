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
