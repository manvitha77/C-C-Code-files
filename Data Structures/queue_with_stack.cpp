// Implementing stack using queues

#include <iostream>
using namespace std;
#define MAX 20

//Define class queue with basic queue functionalities
class queue
{
    int rear, front;
    int arr[MAX];
    public:
    queue()
    {
        front=rear=-1;
    }
    int enqueue(int x);
    int* dequeue();
    void display();
    int get_size();
    int get_front();
};
int queue:: get_front()
{
    return front;
}
int queue:: get_size()
{
    return rear;
}
int queue :: enqueue(int x)
{
    if(rear>MAX-1)
    {

        return 0;
    }
    else if(front==-1)
    {
        front++;
    }
    arr[++rear]=x;
    return 1;

}

int* queue :: dequeue()
{   int *x=NULL;
    if(front==-1)
    {
        return x;

    }
    else
    {
        x=&arr[front++];
        return x;
    }

}
void queue :: display()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[i]<<endl;
    }
}


//define stack class using queue class defined above
class stack{
    queue q;
    public:
    void push(int x);
    void pop();
    void display();
};

void stack :: push(int x)
{
    int y;
    int *p;
    if(q.enqueue(x))
    	cout<<"Successfully Inserted\n";
    else
    	cout<<"Stack is Full";
    int s=q.get_size();
    int f=q.get_front();
    for(int i=f;i<s;i++)
    {
      // y=q.enqueue(q.dequeue());
    	p=q.dequeue();
    	y=q.enqueue(*p);

    }
}

void stack:: pop()
{   int *p;
    p=q.dequeue();
    if(p==NULL)
    {
    	cout<<"Stack is Empty\n";
    }
    else
    {
    	cout<<"Number "<<*p<<" is deleted\n";
    }

}

void stack :: display()
{
    q.display();
}

int main() {
  stack s;
  int choice;
    int input;
    do
    {
 	   cout<<"Enter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
 	   cin>>choice;
 	   switch(choice)
 	   {
 	   case 1:
 		   cout<<"Enter number to be pushed\n";
 		   cin>>input;
 		   s.push(input);
 		   break;
 	   case 2:
 		   s.pop();
 		   break;
 	   case 3:
 		   s.display();
 		   break;
 	   case 4:
 		   break;
 	   default:
 		   cout<<"Please enter valid value for choice\n";
 		   break;
 	   }
    }while(choice!=4);
    cout<<"\nExiting....";
 /* s.push(10);
  s.push(20);
  s.push(30);
  s.display();
  s.pop();
  s.display();*/
}
