#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int state[MAX];
int f=-1,r=-1;

struct node
{
    int dest;
    struct node* next;
};

struct list
{
    struct node * head;
};

struct graph
{
    int v;
    struct list* array;

};

void insert_queue(int v)
{
    if(r>=MAX-1)
     printf("full\n");
    else
    {
        if(f==-1)
            f=0;
        r+=1;
        queue[r]=v;
    }

}
int isEmpty()
{
    if(f==-1||f>r)
        return 1;
    return 0;

}

int delete_queue()
{    int x;
    if(f==-1||f>r)
        exit(1);
    x=queue[f];
    //printf("cc%d ",f);
    f=f+1;
    return x;
}

struct node* newNode(int num)
{
  struct node* n=(struct node*)malloc(sizeof(struct node));
  n->dest=num;
  n->next=NULL;
  return n;
}

struct graph* newGraph(int v)
{
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->v=v;
    g->array= (struct list*)malloc(v*sizeof(struct list));
    int i;
    for(i=0;i<v;i++)
    {
        g->array[i].head=NULL;
    }
    return g;
}

void addEdge(struct graph* g, int s, int d)
{
    struct node* n=newNode(d);
   n->next=g->array[s].head;
    g->array[s].head=n;


}

void print(struct graph* g)
{
    int v;
    for(v=0;v<g->v;v++)
    {
        struct node* n = g->array[v].head;

        printf("\nSource-%d\nDestinations -  ",v);

        while(n)
        {
            printf("%d ",n->dest);
            n=n->next;
        }
    }
    printf("\n");
}

int search(struct graph* g,int src,int dest)
{
    struct node* n=g->array[src].head;
    while(n)
    {
        if(n->dest==dest)
            return 1;
        n=n->next;
    }
    return 0;

}

void bfs(int v,struct graph* g)
{
    printf("Result of Breadth First Search at Vertex %d\n",v);
	int i;
    for(i=0;i<4;i++)
        state[i]=0;
    insert_queue(v);
    while(!isEmpty())
    {
        v=delete_queue();
        printf("%d ",v);
        state[v]=1;
        for(i=0;i<4;i++)
        {
            if(search(g,v,i)==1&&state[i]==0)
            {
                insert_queue(i);
                state[i]=2;

            }
        }
    }
    printf("\n");
}

int main()
{  setvbuf(stdout, NULL, _IONBF, 0);
   printf("Please enter the number of vertices in your graph\n");
   int v;
   scanf("%d",&v);
   struct graph* g=newGraph(v);
   int choice;
          int src,dest;
          do
          {
       	   printf("Enter your choice\n1.Add Edge\n2.Print Graph\n3.Search an Edge\n4.Breadth First Search\n5.Exit\n");
       	   scanf("%d",&choice);
       	   switch(choice)
       	   {
       	   case 1:
       		   printf("Enter source of the edge\n");
       		   scanf("%d",&src);
       		  printf("Enter destination of the edge\n");
       	    	scanf("%d",&dest);
       		   addEdge(g,src,dest);
       		   break;
       	   case 2:
       		  print(g);
       		  break;
       	   case 3:
       		printf("Enter source of the edge to be searched\n");
       		scanf("%d",&src);
       		printf("Enter destination of the edge to be searched\n");
       		scanf("%d",&dest);
       		if(search(g,src,dest))
       			printf("Edge Found\n");
       		else
       			printf("Edge not found\n");
          break;
       	  case 4:
       		  printf("Enter the vertex at which Breadth First Search needs to be performed\n");
       	      scanf("%d",&src);
       	      bfs(src,g);
       		 break;
       	  case 5:
       		  break;
       	  default:
       		   printf("Please enter valid value for choice\n");
       		   break;
       	   }
          }while(choice!=5);
          printf("\nExiting....");

    return 0;
}
