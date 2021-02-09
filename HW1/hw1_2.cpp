#include <stdio.h>
#include <stdlib.h>
void hanoi(int,char,char,char);
int time = 0;

int main()
{
	int n;
	printf("Please enter the height of hanoi tower:");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	printf("Total steps:%d\n", time);
	return 0;
}

void hanoi(int n,char A,char B,char C)
{
	if(n==1)
	{
		printf("%d:Move disk %d from %c to %c\n", ++time, n, A, C);
	}

	else
	{
		hanoi(n - 1, A, C, B);
		printf("%d:Move disk %d from %c to %c\n", ++time, n, A, C);
		hanoi(n - 1, B, A, C);
	}

}
