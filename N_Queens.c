//N Queens

#include <stdio.h>
#include <stdlib.h>
#define N 8
void print(int** board,int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}
int isSafe(int** board,int row,int col,int m)
{
    int i;
    int j;
    for(i=0;i<col;i++)
        if(board[row][i])
            return 0;
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j])
            return 0;
    for(i=row,j=col;i<m&&j>=0;i++,j--)
        if(board[i][j])
            return 0;
    return 1;
}
int solve(int** board,int col,int m)
{   int i;
    if(col>=m)
        return 1;
    else
    {
        for(i=0;i<m;i++)
        {
            if(isSafe(board,i,col,m))
            {
                board[i][col]=1;
                if(solve(board,col+1,m))
                    return 1;
                board[i][col]=0;
            }
        }
        return 0;
    }
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
int m;
printf("Enter the size of the table\n");
scanf("%d",&m);
//int board[N][N];
int **ptr=(int **)malloc(m*sizeof(int *));
int i,j;
for(i=0;i<m;i++)
{
	ptr[i]=(int*)malloc(m*sizeof(int));
    for(j=0;j<m;j++)
        ptr[i][j]=0;
}
if(solve(ptr,0,m))
{   printf("Below is the solution for the N-Queens problem with N = %d\n",m);
    print(ptr,m);
}
else
    printf("Solution is not possible\n");

}
