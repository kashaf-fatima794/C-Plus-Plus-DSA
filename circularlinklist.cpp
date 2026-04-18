#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head=NULL;

void insert(int val)
{
    node* newNode=new node();
    newNode->data=val;
    
    if(head==NULL)
	{
        head=newNode;
        newNode->next=head;
    }else
	{
        node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }
}

int maxx()
{
    if(head==NULL)
	{
        cout<<"empty";
        return -1;
    }
    int mx=head->data;
    node* t=head->next;
    do
	{
        if(t->data>mx) 
		mx=t->data;
        t=t->next;
    }
	while(t!=head);
    return mx;
}

int minn(){
    if(head==NULL)
	{
        cout<<"empty";
        return -1;
    }
    int mn=head->data;
    node* t=head->next;
    do
	{
        if(t->data<mn) mn=t->data;
        t=t->next;
    }
	while(t!=head);
    return mn;
}

void update(int pos,int val)
{
    if(head==NULL) return;
    node* t=head;
    int i=0;
    do
	{
        if(i==pos)
		{
            t->data=val;
            return;
        }
        t=t->next;
        i++;
    }
	while(t!=head);
    cout<<"not found";
}

void selection()
{
    if(head==NULL||head->next==head) return;
    node* t=head;
    do
	{
        node* min=t;
        node* r=t->next;
        while(r!=head)
		{
            if(r->data<min->data) min=r;
            r=r->next;
        }
        int temp=t->data;
        t->data=min->data;
        min->data=temp;
        t=t->next;
    }
	while(t->next!=head);
}

void display()
{
    if(head==NULL) return;
    node* t=head;
    do
	{
        cout<<t->data<<" ";
        t=t->next;
    }
	while(t!=head);
    cout<<endl;
}

int main()
{
    insert(40);
    insert(10);
    insert(30);
    insert(20);
    
    cout<<"List: ";
    display();
    
    cout<<"Max: "<<maxx()<<endl;
    cout<<"Min: "<<minn()<<endl;
    
    update(2,50);
    cout<<"Updated: ";
    display();
    
    selection();
    cout<<"Sorted: ";
    display();
    
    return 0;
}
