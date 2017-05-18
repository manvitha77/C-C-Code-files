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



int main() {
  link l;

  int choice;
      int input;
      int data;
      node *n;
      do
      {
   	   cout<<"Enter your choice\n1.Insert Data at Front\n2.Insert Data at Last\n3.Insert after given Data\n";
   	   cout<<"4.Display\n5.Search Data\n6.Get count of the Data in the list\n";
   	   cout<<"7.Delete a node with given data\n8. Delete last node\n9.Exit\n";
   	   cin>>choice;
   	   switch(choice)
   	   {
   	   case 1:
   		   cout<<"Enter number to be inserted\n";
   		   cin>>input;
   		   n=new node(input);
   		   l.addAtFront(n);
   		   break;
   	   case 2:
   		cout<<"Enter number to be inserted\n";
   		   		   cin>>input;
   		   		   n=new node(input);
   		   		   l.addAtEnd(n);
   		   		   break;
   	   case 3:
   		   cout<<"Enter the data at the node after which insertion is to be done\n";
   		   cin>>data;
   		cout<<"Enter number to be inserted\n";
   		   		   cin>>input;
   		   		   n=new node(input);
   		   		   l.insertAfterGivenData(data,n);
   		   break;
   	   case 4:
   		   l.display();
   		   break;
   	   case 5:
   		cout<<"Enter number to be searched\n";
   		   		   cin>>input;
   		   		   n=l.search(input);
   		   		   if(n!=NULL)
   		   			   cout<<"Element Found\n";
   		   		   else
   		   			   cout<<"ELement is not present in the list\n";
   		break;
   	   case 6:
   		   cout<<"count of the data stored in the list is "<<l.getCount()<<endl;
   		   	break;
   	   case 7:
   		cout<<"Enter number to at the node which is to be deleted\n";
   		cin>>input;
   		n= l.deleteNode(input);
   		if(n==NULL)
   			cout<<"Element to be deleted is not found\n";
   		else
   			cout<<"Element is deleted\n";
   		break;
   	   case 8:
   		n= l.deleteLast();
   		if(n==NULL)
   			cout<<"List is empty\n";
   		else
   			cout<<"Last element is deleted\n";
   		break;
   	   case 9:
   		   break;
   	   default:
   		   cout<<"Please enter valid value for choice\n";
   		   break;
   	   }
      }while(choice!=9);
      cout<<"\nExiting....";

}
