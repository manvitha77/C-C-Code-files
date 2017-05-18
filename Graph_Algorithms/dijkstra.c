#include <stdio.h>
#include <stdlib.h>

#define intMax 1000
//const int V=9;
void print(int *parent,int size,int** graph)
{
    int i,j;
    printf("Parent-Child Weight\n");
    for(i=0;i<size;i++)
    {   if(parent[i]!=-1)
    {    j=parent[i];
         printf("%d-%d %d\n",j,i,graph[j][i]);
    }
    }
}
int minkey(int* key,int* mstSet,int size)
{
    int min=intMax,minIndex;
    int i;
    for(i=0;i<size;i++)
    {
        if(key[i]<min&&mstSet[i]==0)
        {
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void primMST(int **graph,int size)
{
	int* parent=(int*)malloc(size*sizeof(int));
	    int* key=(int*)malloc(size*sizeof(int));
	    int* mstSet=(int*)malloc(size*sizeof(int));
    int i;
    for(i=0;i<size;i++)
    {
        key[i]=intMax;
        mstSet[i]=0;
    }
    int src;
   // key[0]=0;
  //  parent[0]=-1;
    printf("Enter the source vertex for your Prims Minimum Spanning Tree\n");
       scanf("%d",&src);
       key[src]=0;
       parent[src]=-1;
    int u;
    int v;
    for(i=0;i<size-1;i++)
    {
    	u=minkey(key,mstSet,size);
        mstSet[u]=1;
        for(v=0;v<size;v++)
        {
            if(graph[u][v]&&mstSet[v]==0&&key[u]+graph[u][v]<key[v])
            {
                key[v]=graph[u][v]+key[u];
                parent[v]=u;
            }
        }

    }
    print(parent,size,graph);
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int i,j;
	  printf("Enter the number of vertices in your graph\n");
	  int v;
	  scanf("%d",&v);
	  int **graph=(int **)malloc(v*sizeof(int *));

	  printf("Enter the Adjacency Matrix for your graph\n");
	  for(i=0;i<v;i++)
	  {   graph[i]=(int*)malloc(v*sizeof(int));
		  printf("Enter for vertex %d\n",i);
		  for(j=0;j<v;j++)
			  scanf("%d",&graph[i][j]);
	  }

 /* int graph[9][9] =  {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };*/


    // Print the solution
  primMST(graph,v);
}
