#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int v)
	{
        data=v;
        left=right=NULL;
    }
};

node* insert(node* root,int v)
{
    if(root==NULL) 
	    return new node(v);
    if(v<root->data)
        root->left=insert(root->left,v);
    else
        root->right=insert(root->right,v);
    return root;
}

bool search(node* root,int v)
{
    if(root==NULL)
	    return false;
    if(root->data==v) 
	    return true;
    if(v<root->data)
        return search(root->left,v);
    else
        return search(root->right,v);
}

node* findMin(node* root)
{
    while(root->left!=NULL) 
	   root=root->left;
    return root;
}

node* deleteNode(node* root,int v)
{
    if(root==NULL) 
	    return root;
    if(v<root->data)
        root->left=deleteNode(root->left,v);
    else if(v>root->data)
        root->right=deleteNode(root->right,v);
    else
	{
        if(root->left==NULL)
		{
            node* t=root->right;
            delete root;
            return t;
        }
		else if(root->right==NULL)
		{
            node* t=root->left;
            delete root;
            return t;
        }
        node* t=findMin(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}

void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    cout<<"BST Inorder: ";
    inorder(root);
    cout<<endl;

    int k=40;
    if(search(root,k)) 
	    cout<<k<<" found"<<endl;
    else 
	    cout<<"not found"<<endl;

    cout<<"Deleting 20..."<<endl;
    root=deleteNode(root,20);
    
    cout<<"After deletion: ";
    inorder(root);
    cout<<endl;

    return 0;
}
