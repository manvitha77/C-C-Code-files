#include <stdio.h>
#include <stdlib.h>

#define intMax 1000


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
    int src;
    for(i=0;i<size;i++)
    {
        key[i]=intMax;
        mstSet[i]=0;
    }
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
            if(graph[u][v]&&mstSet[v]==0&&graph[u][v]<key[v])
            {
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }

    }
    print(parent,size,graph);
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Enter the number of vertices in your graph\n");
	int v;
	int i,j;
	scanf("%d",&v);
	int **graph=(int **)malloc(v*sizeof(int *));
	printf("Please enter the adjacency matrix of your graph\n");
	for(i=0;i<v;i++)
	{    graph[i]=(int*)malloc(v*sizeof(int));
		printf("Enter for vertex %d\n",i);
		for(j=0;j<v;j++)
			scanf("%d",&graph[i][j]);
	}
	printf("\n");

    primMST(graph,v);
}
