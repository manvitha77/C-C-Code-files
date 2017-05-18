#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len;
int n=0;

//create factorial function used to calculate total permutations possible for a string of length x

int factorial(int x)
{
	int i,fact;
	fact=1;
	for(i=1;i<=x;i++)
	{
		fact=fact*i;
	}
	return fact;
}

// create swap function to swap given two characters

void swap(char *a, char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

//permute function which is called recursively to generate all the possible permutations of the given string

void permute(char** perm,char *a, int low,int high)
{
    int i,j;

    if(low==high)
       {
    	   for(j=0;j<n;j++)
    	   {
    		   if(strcmp(perm[j],a)==0)
    			   break;
    	   }
    	   if(j==n)
    	   {
    		   perm[n]=(char *)malloc((high+2)*sizeof(char));
    		   strcpy(perm[n],a);
    		   n++;
    	   }

       }
    else
    {
        for(i=low;i<=high;i++)
        {
        	swap((a+low),(a+i));
            permute(perm,a,low+1,high);
            swap((a+low),(a+i));

        }
    }

}
int main()
{
  int i;
  setvbuf(stdout, NULL, _IONBF, 0);
  char str[20];
  printf("Enter string to be permuted. String length should be atleast 1\n");
  gets(str);
  len=strlen(str);
  int total_perm=factorial(len);
  char **perm= (char **)malloc(total_perm*sizeof(char *));
  permute(perm,str,0,len-1);

  printf("\nFollowing are the permutations possible for the given string '%s'\n\n",str);
  for(i=0;i<n;i++)
    {
        printf("%s\n",perm[i]);
    }

}
