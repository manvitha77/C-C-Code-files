#include <iostream>
using namespace std;
#define MAX 20

//Define class queue with methods for inserting and deleting the elements in FIFO fashion
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
    void dequeue();
    void display();
};

int queue :: enqueue(int x)
{
    if(rear>MAX-1)
    {
        cout<<"Queue is full"<<endl;
        return 0;
    }
    else if(front==-1)
    {
        front++;
    }
    arr[++rear]=x;
    return 1;

}

void queue :: dequeue()
{   int x;
    if(front==-1)
    {
        cout<<"queue is empty"<<endl;

    }
    else
    {
        x=arr[front++];
        cout<<"Number "<<x<<" is deleted";
    }

}
void queue :: display()
{    cout<<"Current Elements in the queue:\n";
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
   queue q;
   int choice;
   int input;
   do
   {
	   cout<<"Enter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
	   cin>>choice;
	   switch(choice)
	   {
	   case 1:
		   cout<<"Enter numbe to be inserted\n";
		   cin>>input;
		   if(q.enqueue(input))
			   cout<<"Successfully Inserted\n";
		   else
			   cout<<"Queue is full";
		   break;
	   case 2:
		   q.dequeue();
		   break;
	   case 3:
		   q.display();
		   break;
	   case 4:
		   break;
	   default:
		   cout<<"Please enter valid value for choice\n";
		   break;
	   }
   }while(choice!=4);
   cout<<"\nExiting....";
 /*  q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.display();
   cout<<"deq "<<q.dequeue()<<endl;;
   q.display();*/
}
