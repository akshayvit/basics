#include <stdio.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createnode(int d)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=d;
	n->left=n->right=NULL;
	return n;
}

struct node* insert(struct node* root,int d)
{
	if(root==NULL)
	{
		return createnode(d);
	}
	if(d>root->data)
	{
		 root->right=insert(root->right,d);
	}
	else
	{
	   	 root->left=insert(root->left,d);
	}
	return NULL;
}

bool isthere(struct node* r1,struct node* r2)
{
	if(r1==NULL && r2==NULL )
	{
		return true;
	}
	if(r2==NULL && r1!=NULL )
	{
		return false;
	}
    return (r1->data==r2->data) && isthere(r1->right,r2->right)&& isthere(r1->left,r2->left);
}

bool subtree(struct node* root1,struct node* root2)
{
	if(root2->data==root1->data)
	{
		return isthere(root1,root2);
	}
	return subtree(root1->left,root2) || subtree(root1->right,root2);
}
main()
{
	struct node* T=createnode(5);
	T->right         = createnode(3);  
    T->right->right = createnode(3);  
    T->left         = createnode(10);  
    T->left->left     = createnode(4);  
    T->left->left->right = createnode(30);  
    T->left->right     = createnode(6); 
    struct node *S = createnode(10);  
    S->right     = createnode(6);  
    S->left     = createnode(4);  
    S->left->right = createnode(30);  
    printf("%d",subtree(T,S));
}
