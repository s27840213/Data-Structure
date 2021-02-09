#include <stdio.h>

int find(int *parent,int x);
void Union(int *parent,int i,int j,int height1,int hight2);


int main()
{
    int n;
    scanf("%d",&n);
    printf("\n");
    int parent[n],i;
    for(i=0;i<n;i++)
    {
    	 parent[i] = -1;
    }
    for(i=1;i<n;i++)
    {
        Union(parent,0,i,find(parent,0),find(parent,i));
    }
    printf("NODE\tparent\n");
    for(i=0;i<n;++i)
    {
        printf("%d\t",i);
        if (parent[i] < 0)  
	{
            printf("root\n");
            continue;
        }
        printf("%d\n",parent[i]);
    }
    return 0;
}

int find(int *parent,int x)
{
    int root;
    for(root = x;parent[x] >= 0;x = parent[x])
    ;
    return parent[x];
}
void Union(int *parent,int i,int j,int height1,int height2)
{
    if(height1 > height2){
        parent[i] = j;
    }
    else if(height1 < height2){
        parent[j] = i;
    }
    else {
        parent[j] = i;
        parent[i] = parent[i] - 1;
    }
}
