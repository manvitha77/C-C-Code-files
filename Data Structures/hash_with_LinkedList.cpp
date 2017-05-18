#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 10;

/*
 * HashNode Class Declaration
 */
class HashNode
{
    public:
    int key;
	int value;
	HashNode* next;

	HashNode(int key, int value)
        {
            this->key = key;
	    this->value = value;
	    this->next = NULL;
        }
};

/*
 * HashMap Class Declaration
 */
class HashMap
{
    private:
        HashNode** htable;
    public:
        HashMap()
        {
            htable = new HashNode*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                htable[i] = NULL;
        }
        ~HashMap()
        {
            for (int i = 0; i < TABLE_SIZE; ++i)
	    {
                HashNode* entry = htable[i];
                while (entry != NULL)
	        {
                    HashNode* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] htable;
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
            int hash_val = HashFunc(key);

            HashNode* entry = htable[hash_val];
             if (entry == NULL)
            {
                entry = new HashNode(key, value);
                htable[hash_val] = entry;
            }
            else
            {

            while (entry->next != NULL)
            {

                entry = entry->next;
            }

                entry->next = new HashNode(key, value);



             }

        }
        /*
         * Remove Element at a key
         */
        void remove(int key)
        {
            int hash_val = HashFunc(key);
            HashNode* entry = htable[hash_val];
            HashNode* prev = NULL;
            if (entry == NULL)
            {
            	cout<<"No Element found at key "<<key<<endl;
                return;
            }
            while (entry != NULL)
	    {       if(entry->key==key && entry == htable[hash_val])
	            {
	                htable[hash_val]=entry->next;
	                entry=htable[hash_val];
	            }
	            else if(entry->key!=key)
	            {
	                prev=entry;
	                entry=entry->next;
	            }
	            else if(entry->key==key)
	            {
	                prev->next=entry->next;
	                entry=entry->next;
	            }

            }

            cout<<"Element Deleted"<<endl;
        }
        /*
         * Search Element at a key
         */
        void search(int key)
        {
            bool flag = false;
            int hash_val = HashFunc(key);
            HashNode* entry = htable[hash_val];
            while (entry != NULL)
	    {
                if (entry->key == key)
	            {
                    cout<<entry->value<<" ";
                    flag = true;
                }
                entry = entry->next;
            }
            cout<<endl;
            if (!flag)
                cout<<"Not found\n";
        }

        void display()
        {
        	int flag=0;
        	   for (int i = 0; i < TABLE_SIZE; ++i)
        		    {
        	                HashNode* entry = htable[i];
        	                while (entry != NULL)
        		        {       flag=1;
        	                    cout<<"key-"<<entry->key<<", value-"<<entry->value<<endl;

        	                    entry = entry->next;


        	            }

        	        }
        	   if(flag==0)
        		   cout<<"No elements in the Hash Map to display\n";
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
