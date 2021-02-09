#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

int recur(int n,int k)
{
if(n==k || k==0)
	return 1;
else
	return recur(n-1,k)+recur(n-1,k-1);
}
int main(int argc,char *argv[])
{
int n,k;
n = atoi(argv[1]);
k = atoi(argv[2]);
int answer = 0;
answer = recur(n,k);
printf("(n,k) = %d,%d\n",n,k);
printf("the binomial coefficient of x^%d : %d\n",k,answer);
return 0;
}

