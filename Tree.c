#include<stdio.h> // printf
#include<stdlib.h> // malloc

struct Node
{
    int data;
    struct Node *left,*right;
};
Insertar (struct Node **root,int v )
{
	if(*root==NULL)
	{
		struct Node *leaf=(struct Node *)malloc(sizeof(struct Node ));
		leaf->data=v;
		leaf->right=NULL;
		leaf->left=NULL;
		*root= leaf;
   }
   else if((*root)->data>v)
		Insertar(&root->right, v);
	else 
		Insertar(&root->left,v);
}
int main()
{
    struct Node *root=NULL;
	
	return 0;
}
