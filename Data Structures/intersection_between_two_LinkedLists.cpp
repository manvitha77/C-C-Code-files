#include <iostream>
using namespace std;

//create node class
class node
{   public:
    int data;
    node *next;
    node()
    {
        data=0;
        next=NULL;

    }
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

//create  link class with basic functionalities of a linked list
class link
{
    public:
    node *head;
    void addAtFront(node *n);
    void addAtEnd(node *n);
    node *getLastNode();
    node *search(int x);
    node *deleteNode(int x);
    node *deleteLast();
    void display();
    void insertAfterGivenData(int x,node *n);
    int getCount();

    link()
    {
        head=NULL;
    }
};

void link :: addAtFront(node *n)
{
    n-> next=head;
    head=n;
}

void link :: addAtEnd(node *n)
{
  node *ptr=getLastNode();
  ptr->next=n;

}

node * link :: getLastNode()
{
    node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr;
}

node * link :: search(int x)
{
    node *ptr = head;
    while(ptr!=NULL && ptr->data!=x)
    {
        ptr=ptr->next;
    }

    return ptr;
}

node * link :: deleteNode(int x)
{
    node *ptr= search(x);
    if(ptr==NULL)
        return ptr;
    if(head==ptr)
        head=head->next;
    else
    {
        node *n=head;
        while(n->next!=ptr)
        {
            n=n->next;
        }
        n->next=ptr->next;

    }

    return ptr;
}

void link :: insertAfterGivenData(int x, node *n)
{
    node *ptr=search(x);
    if(ptr==NULL)
    {
        cout<<"insert failed\n\n"<<endl;
        return;
    }
    n->next=ptr->next;
    ptr->next=n;

}
void link :: display()
{
    node *ptr=head;
    if(ptr==NULL)
    {
    	cout<<"Sorry No data to print\n\n";
    }
    else
    {
    cout<<"Following is the data stored in list\n" 	;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    }
}
node * link :: deleteLast()
{
    node *ptr=head;
    if(head==NULL)
    return ptr;
    if(head->next==NULL)
    {
        head=head->next;
        return ptr;
    }
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *d=ptr->next;
    ptr->next=NULL;
    return d;
}
int link :: getCount()
{
    int c=0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr-> next;
    }

    return c;
}

//code for finding any intersection between given 2 linked lists

int* intersectNode(int d,link m,link n)
{
    int i;
    node *c1=m.head;
    node *c2=n.head;
    int *p=NULL;
    for(i=0;i<d;i++)
    {
        c1=c1->next;
    }
    while(c1!=NULL&&c2!=NULL)
    {
        if(c1==c2)
        {
        	p=&(c1->data);
            return p;
        }
        c1=c1->next;
        c2=c2->next;
    }
    return p;
}


int* getIntersectNode(link m,link n)
{
    int c1=m.getCount();
    int c2=n.getCount();
    int d;
    if(c1>c2)
    {
        d=c1-c2;
        return intersectNode(d,m,n);
    }
    else
    {
        d=c2-c1;
        return intersectNode(d,n,m);
    }

}


int main() {

  link l,m;;
   int *p;
   node *n= new node(10);
   l.addAtFront(n);
   l.addAtEnd(new node(20));
   l.insertAfterGivenData(10,new node(30));
   n=new node(40);
   l.addAtEnd(new node(50));
   l.insertAfterGivenData(30,n);
   m.addAtFront(new node(90));
   m.addAtEnd(n);
   l.display();
   m.display();
   p=getIntersectNode(l,m);
   if(p!=NULL)
	   cout<<"Intersection is found at the data "<<*p<<endl;
   else
	   cout<<"There is no intersection\n";


}
