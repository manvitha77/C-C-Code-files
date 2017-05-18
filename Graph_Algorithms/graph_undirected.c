#include <stdio.h>
#include <stdlib.h>

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
    n=newNode(s);
    n->next=g->array[d].head;
    g->array[d].head=n;

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
       	   printf("Enter your choice\n1.Add Edge\n2.Print Graph\n3.Search an Edge\n4.Exit\n");
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
       		 break;
       	  default:
       		   printf("Please enter valid value for choice\n");
       		   break;
       	   }
          }while(choice!=4);
          printf("\nExiting....");

    return 0;
}
