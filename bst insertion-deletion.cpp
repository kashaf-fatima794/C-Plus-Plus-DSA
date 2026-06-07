#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int val)
	{
        data=val;
        left=right=NULL;
    }
};

Node* insert(Node* root,int val)
{
    if(root==NULL) 
	return new Node(val);
    if(val<root->data)
        root->left=insert(root->left,val);
    else if(val>root->data)
        root->right=insert(root->right,val);
    return root;
}

Node* findMin(Node* root)
{
    while(root->left!=NULL) 
	root=root->left;
    return root;
}

Node* remove(Node* root,int val)
{
    if(root==NULL)
	 return root;
    if(val<root->data)
        root->left=remove(root->left,val);
    else if(val>root->data)
        root->right=remove(root->right,val);
    else{
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp=findMin(root->right);
            root->data=temp->data;
            root->right=remove(root->right,temp->data);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if(root==NULL) 
	return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);

    cout<<"Tree: ";
    inorder(root);
    cout<<endl;

    root=remove(root,20);
    root=remove(root,30);
    root=remove(root,50);

    cout<<"After Delete: ";
    inorder(root);
    cout<<endl;

    return 0;
}
