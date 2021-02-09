#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
	int n = atoi(argv[1]);
	int cb[n][n];
	int ktmove1[8] = {-2,-1,1,2,2,1,-1,-2};
	int ktmove2[8] = {1,2,2,1,-1,-2,-2,-1};
	int nexti[8] = {0};
	int nextj[8] = {0};
	int exits[8] = {0};
	int a,b;
	int i,j,k,m,l,npos,temp,min;
	int tempi,tempj,tempk,templ;
	for(a=0;a<n;a++)
		{
			for(b=0;b<n;b++)
			{
				cb[a][b] = 0;
			}
		}
	if(n<1||n>8)
	{
		printf("Error!Please follow the rule:0 <= n <=8\n");
		exit(0);
	}
	 //Set the number 1 at square(0, 0) of chess board. 
	printf("%d:\n",n);
	i = 0;
	j = 0;
	cb[i][j] = 1;
	for(m=2;m<=(n*n);m++)
	{
		for(l=0;l<8;l++)
			exits[l] =0;
		l = 0;
		for(k=0;k<8;k++)
		{
			tempi = i + ktmove1[k];
			tempj = j + ktmove2[k];
			if(tempi<0 || tempj<0 || tempi>(n-1) ||tempj>(n-1))
				continue;
			if(cb[tempi][tempj] == 0)
			{
				nexti[l] = tempi;
				nextj[l] = tempj;
				l++;
			}
		}
		npos = l;
		if(npos == 0)
		{
		printf("No solution! Bye~\n");
		return 0;
		}
		else if(npos == 1)
		{
			min = 0;
		}
		else
		{
			for(l=0;l<npos;l++)
			{
				for(k=0;k<8;k++)
				{
					tempk = nexti[l] + ktmove1[k];
					templ = nextj[l] + ktmove2[k];
					if(tempk<0 || templ<0 || tempk>(n-1) ||templ>(n-1))
					{
						continue;
					}
					if(cb[tempk][templ] == 0)
						exits[l]++;
				}
			}
			temp = exits[0];
			min = 0;
			for(l = 1;l<npos;l++)
			{
				if(exits[l] <temp)
				{
					temp = exits[l];
					min = l;
				}
			}
		}
		i = nexti[min];
		j = nextj[min];
		cb[i][j] = m;
	}
	for(a=0;a<n;a++)
	{
		if(a!=0)
		printf("\n");
		for(b=0;b<n;b++)
		{
			printf("%2d ",cb[a][b]);
		}
	}
	printf("\n");
	return 0;
}


