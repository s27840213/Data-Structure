#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int data;
	struct node* np;
};
struct node* head;
struct node* tail;
struct node* xor(struct node* a,struct node* b)
{
	return (struct node*)((unsigned long)a^(unsigned long)b);
}
/*struct node*  get(int x)
{
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn ->data  = x;
	return newn;
}*/
void insert(int x)
{
	//struct node* newn = get(x);
	struct node *newn = (struct node*) malloc(sizeof(struct node));
	newn->data = x;
	if(head == NULL)
	{
		newn->np =NULL;
		head = tail = newn;
	}
/*	else if(at_tail)
	{
		newn->np = xor(tail,NULL);
		tail->np = xor(newn,xor(tail->np,NULL));
	}*/
	else
	{
		newn->np = xor(NULL,head);
		head->np = xor(newn,xor(NULL,head->np));
		head = newn;
	}
}
void create()
{
	int i = 0;
	for(i=20;i>=1;i--)
	{
		insert(i);
	}
}
void left_to_right()
{
	struct node *temp = head;
	struct node *prev = NULL,*next;
	 printf("The data from left to right:\n");
	while(temp !=NULL)
	{
		printf("%d ",temp->data);
		next = xor(prev,temp->np);
		prev = temp;
		temp = next;
	}
	printf("\n");
}
void right_to_left()
{
    struct node *temp = head;
	struct node *prev=NULL ,*next,*last=NULL;
	printf("The data from right to left:\n");
	while(temp->data<20)
	{
		next = xor(prev,temp->np);
		prev = temp;
		temp = next;
	}
	while(temp !=NULL)
	{
		printf("%d ",temp->data);
		prev = xor(temp->np,last);
		last = temp;
		temp = prev;
	}
	printf("\n");
/*	while(temp !=NULL)
	{
		printf("%d ",temp->data);
		next = xor(next,temp->np);
		next = temp;
		temp = prev;
	}*/
}



int  main()
{
	head = NULL;
	create();
	left_to_right();
	right_to_left();
}

