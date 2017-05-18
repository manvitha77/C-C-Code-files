//m colorinng

#include <stdio.h>
#include <stdlib.h>

void print(int *color,int size)
{   printf("Vertex-Color\n");
    int i;
    for(i=0;i<size;i++)
        printf("%d-%d\n",i,color[i]);
}
int isSafe(int **graph,int c,int *color,int v,int size)
{   int i;
    for(i=0;i<size;i++)
    {
        if(graph[v][i]&&color[i]==c)
            return 0;

    }
    return 1;
}
int graphColor(int **graph,int m,int *color,int v,int size)
{
   if(v==size)
    return 1;
    int c;
    for(c=1;c<=m;c++)
    {
        if(isSafe(graph,c,color,v,size))
        {
            color[v]=c;
            if(graphColor(graph,m,color,v+1,size))
                return 1;
            color[v]=0;
        }
    }
    return 0;
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

  int m;
  printf("Enter the number of colors you want to use\n");
  scanf("%d",&m);
  int *color=(int *)malloc(v*sizeof(int));
  for(j=0;j<v;j++)
	  color[j]=0;

  if(graphColor(graph,m,color,0,v))
    print(color,v);
  else
    printf("No solution possible with %d colors\n",m);


}
