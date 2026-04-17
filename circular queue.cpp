#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
public:
	Node(int val)
	{
		data=val;
		next=NULL;
	}
};

class queue{
	Node* head;
	Node* tail;
public:
	queue()
	{
		head=tail=NULL;
	}
	
//is empty
	bool isempty()
	{
	return head==NULL;
	}
	
//isfull	
	bool isfull()
	{
		return false;
	}
	
void pushback(int val) 
{
    Node* newnode=new Node(val);
    if (head==NULL) 
	{
        head=tail=newnode;
        tail->next=head;
        return;
    }
    tail->next=newnode;
    tail=newnode;
    tail->next=head; 
}

void popfront()
 {
    if (head==NULL)
	 return;

    if (head==tail) { 
        delete head;
        head=tail=NULL;
    } 
	else 
	{
        Node* temp=head;
        head=head->next;
        tail->next=head; 
        delete temp;
    }
}

//displaying first value
int peek()
{
	if(head==NULL)
	{
		cout<<"empty";
		return -1;
	}
	
	return head->data;
}

int rear() {
        if (tail==NULL) {
            cout<<"Queue is empty ";
            return -1;
        }
        return tail->data;
	}
//printing the queue
void printll()
{
	if (head==NULL) 
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    Node* temp=head;
    
    do {
        cout<<temp->data<< " -> ";
        temp=temp->next;
    } while (temp != head); 
    
    cout<<"(Back to Head)"<<endl;
}
};
int main()
{
	 queue s;
	 s.pushback(36);
	 s.pushback(44);
	 s.pushback(9);
	 s.printll();
	 
	 cout<<"queue is empty :"<<( s.isempty() ? "yes" : "no")<<endl;
	 
	 cout<<"queue is full:"<<(s.isfull() ? "yes" : "no")<<endl;
	 
	s.popfront();
	s.popfront();
	 s.printll();
	 
	 cout<<"peek value: "<<s.peek()<<endl;
	 
	 cout<<"rear value: "<<s.rear()<<endl;
	 s.printll();
}
