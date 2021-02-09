#include <stdio.h>
#include <stdlib.h>
int main()
{
    	int edge;
    	int i;
    	scanf("%d",&edge);
    	int stv[edge],edv[edge],rqr[edge];
    	int act_num;
    	for (i=0; i<edge; i++)
    	{
        	scanf("%d\t%d\t%d\t%d",&act_num,&stv[i],&edv[i],&rqr[i]);
    	}
	int maxn1 = -1;
    	for(i=0; i<edge; i++)
    	{
        	if(stv[i] > maxn1)
		maxn1 = stv[i];
    	}
	maxn1 += 1;
    
	int maxn2 = - 1;
    	for(i=0; i<edge; i++)
    	{
        	if(edv[i] > maxn2)
		maxn2 = edv[i];
    	} 
	maxn2+= 1;

	if (maxn2 > maxn1) 
    		maxn1 = maxn2;
    	int ee[maxn2],le[maxn1];
    	for(i=0; i<maxn1; i++)
    	{
        	ee[i] = 0;
    	}
    	for(i=0; i<edge; i++)
    	{
        	if(ee[edv[i]] < ee[stv[i]] + rqr[i])
        	    	ee[edv[i]] = ee[stv[i]] + rqr[i];
    	}
    	for(i=0; i<maxn1; i++)
    	{
        	le[i] = ee[maxn1-1];
    	}
    	for(i=edge-1; i>=0; i--)
    	{
        	if(le[stv[i]] > le[edv[i]] - rqr[i])
            		le[stv[i]] = le[edv[i]] - rqr[i];
    	}
    	printf("a.\n");
	printf("\tee\tle");
	printf("\n");
    	for(i=0; i<maxn1; i++)
    	{
        	printf("%d\t%d\t%d\n",i,ee[i],le[i]);
    	}
	
	printf("\n");
    	int e[edge],l[edge],s[edge];
    	char c[edge];
    	for(i=0; i<edge; i++)
    	{
        	e[i] = 0;
    	}
    	for(i=0;i<edge;i++)
    	{
        	if(e[i] < ee[stv[i]])
        	    e[i] = ee[stv[i]];
    	}
    	for(i=0; i<edge; i++)
    	{
        	l[i] = le[edge-1];
    	}
    	for(i=edge-1;i>=0;i--)
    	{
       		 if(l[i] > le[edv[i]] - rqr[i])
            	l[i] = le[edv[i]] - rqr[i];
    	}

    	for(i=0; i<edge; i++)
    	{
    	    s[i] = l[i] - e[i];
    	    if(s[i] == 0)   c[i] = 'Y';
    	    else    c[i] = 'N';
    	}
    	printf("b.\n");
	printf("\te\tl\ts\tc");
	printf("\n");
    	for(i=0; i<edge; i++)
    	{
    	    printf("%d\t%d\t%d\t%d\t%c",i+1,e[i],l[i],s[i],c[i]);
	    printf("\n");
    	}
	
	    return 0;
	}


