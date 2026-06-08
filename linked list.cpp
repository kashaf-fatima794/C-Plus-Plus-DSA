#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
public:
	node(int d)
	{
	d=data;
	next=NULL;	
	}
};

class ll{
	node *head , *tail;
public:
	ll()
	{
		head=tail=NULL;
	}
	
	void insertatend(int d)
	{
		node* newnode=new node(d);
		if(head==NULL)
		{
			head=tail=newnode;
			return;
		}
		else
		{
		tail->next=newnode;
		tail=newnode;
		}
	}
	
	void deleteatrear()
	{
		node* temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		temp->next=NULL;
	delete temp;
	tail=temp;
		}
	
	void display()
	{
		node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
		temp=temp->next;
		}
	
	}
};
int main()
{
	ll o;
	o.insertatend(10);
	o.insertatend(11);
	o.insertatend(12);
	o.insertatend(13);
	o.insertatend(14);
	o.display();
	o.deleteatrear();
	o.display();
	return 0;
}
