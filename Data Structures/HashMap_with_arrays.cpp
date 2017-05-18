/*
 *C++ Program to Implement Hash Tables using arrays
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 10;

/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        int key;
        int value;
        HashEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

/*
 * HashMap Class Declaration
 */
class HashMap
{
    private:
        HashEntry **table;
    public:
        HashMap()
	{
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        /*
         * Hash Function
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        /*
         * Insert Element at a key
         */
	void insert(int key, int value)
	{
            int hash = HashFunc(key);

            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
	}
        /*
         * Search Element at a key
         */
        void search(int key)
	{
	    int  hash = HashFunc(key);

	    if (table[hash] == NULL)
	        cout<<"Not found\n";
	    else
	        cout<<"Value at the key "<<key<<" is"<<table[hash]->value<<endl;
        }

        /*
         * Remove Element at a key
         */
        void remove(int key)
	{
	    int hash = HashFunc(key);

            if (table[hash] == NULL)
	    {
                cout<<"No Element found at key "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Element Deleted"<<endl;
        }

        void display()
        {
        	int flag=0;
        	for (int i = 0; i< TABLE_SIZE; i++)
        	            {
        	                if(table[i]!=NULL)
        	                {   cout<<"key-"<<table[i]->key<<", value-"<<table[i]->value<<endl;
        	                	flag=1;
        	                }
        	            }

        	if(flag==0)
        		cout<<"No elements in the hash map to display\n";

        }

};


int main()
{
    HashMap hash;

    int choice;
    int key,value;
            do
            {
         	   cout<<"Enter your choice\n1.Insert\n2.Remove\n3.Display\n4.Search\n5.Exit\n";
         	   cin>>choice;
         	   switch(choice)
         	   {
         	   case 1:
         		   cout<<"Enter key to be inserted\n";
         		   cin>>key;
         		  cout<<"Enter value to be inserted\n";
         		  cin>>value;
         		   hash.insert(key,value);;
         		   break;
         	   case 2:
         		  cout<<"Enter key to be removed\n";
         		  cin>>key;
         		  hash.remove(key);
         		  break;
         	   case 3:
         		   hash.display();
         		   break;
         	   case 4:
         		  cout<<"Enter key to be searched\n";
         		  cin>>key;
         		  hash.search(key);
         		   break;
         	   case 5:
         		   break;
         	   default:
         		   cout<<"Please enter valid value for choice\n";
         		   break;
         	   }
            }while(choice!=5);
            cout<<"\nExiting....";



}
