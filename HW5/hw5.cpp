#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node* bst;


bst insert(bst root, int data)
{
	if(data == -1)
		return root;
	bst newn, last, temp;
	newn = new node;
	newn->data = data;
	newn->left =newn->right= NULL;
	
	if(root == NULL)
	{
		root = newn;
		return root;
	}
	else
	{
		for(last = root; last != NULL;)
		{
			temp = last;
			if(last->data > data)
				last = last->left;
			else
				last = last->right;
		}
		if(temp->data > data)
			temp->left = newn;
		else
			temp->right = newn;
	}
	return root;
}
bst create(bst root)
{
	string item, temp;
	stringstream ss;
	cin >> item;
	ss << item;
	while(1)
	{
		getline(ss, temp, ',');
		if(ss.fail())
			break;
		root = insert(root, atoi(temp.c_str()));
	}
	return root;
}

void print(bst root)
{
	if(root == NULL)
		cout << "There's no node in this tree" << endl;
	int count = 1;
	bst* up = NULL;
	bst* down = new bst[count];
	down[0] = root;
	bool finish = false;
	while(!finish)
	{
		finish = true;
		delete []up;
		up = down;
		down = new bst[count*2];
		for(int i = 0; i < count; i++)
		{
			if(up[i] == NULL)
			{
				cout.width(3);
				cout << std::left <<"*";
				down[i*2] = NULL;
				down[i*2 + 1] = NULL;

			}
			else
			{
				cout.width(3);
				cout << std::left << up[i]->data;
				down[i*2] = up[i]->left;
				down[i*2 + 1] = up[i]->right;
				if(down[i*2] != NULL)
					finish = false;
				if(down[i*2 + 1] != NULL)
					finish = false;
			}
		}
		cout << endl;
		count *= 2;
	}
	delete []up;
	delete []down;
}

bool dele(bst *root, int del_item)
{
	bst found = *root;
	bst temp = NULL;
	if(root==NULL)
	{
		cout << "There's no node in this tree" << endl;
		exit(1);
	}
	while(found)
	{
		if(found->data == del_item)
			break;
		temp = found;
		if(found->data > del_item)
			found = found->left;
		else
			found = found->right;
	}	
	if(found==NULL)
		return false;
	if(temp==NULL && (found->right==NULL || found->left==NULL))
	{ 
		if(found->left==NULL && found->right==NULL)
		{
			cout << "There's no node in this tree" << endl;
			exit(1);
		}
		else if(found->left==NULL)
		{
			temp = *root;
			*root = (*root)->right;
			delete temp;
		}
		else if(found->right==NULL)
		{
			temp = *root;
			*root = (*root)->left;
			delete temp;
		}
		return true;
	}

	//No child
	if(found->left==NULL && found->right==NULL)
	{
		if(temp->data > found->data)
			temp->left = NULL;
		else
			temp->right = NULL;
		delete found;
	}	
	//One child
	else if(found->right==NULL)
	{
		if(temp->data > found->data)
			temp->left = found->left;
		else
			temp->right = found->left;
		delete found;
	}
	else if(found->left==NULL)
	{
		if(temp->data > found->data)
			temp->left = found->right;
		else
			temp->right = found->right;
		delete found;
	}
	//Two child
	else
	{
		bst downnode = found->right;
		bst tempnode = found;
		while(downnode->left)
		{
			tempnode = downnode;
			downnode = downnode->left;
		}
		found->data = downnode->data;
		if(tempnode->right == downnode)
		{
			if(downnode->right)
				tempnode->right = downnode->right;
			else
				tempnode->right = NULL;
		}
		else
		{
			if(downnode->right)
				tempnode->left = downnode->right;
			else
				tempnode->left = NULL;
		}
		delete downnode;
	}
	
	return true;
}

int main(){
	char y_or_n;
	int del_item;
	bool check;
	bst root = NULL;
	root = create(root);
	cout << "Create Binary Search Tree" << endl;
	print(root);
	cout << "Delete element?(Y/N):";
	cin >> y_or_n;
	while((y_or_n != 'y')&&(y_or_n != 'Y')&&(y_or_n != 'n')&&(y_or_n != 'N'))
	{
		cout << "Error !"<<endl;
		cout << "Delete element?(Y/N):";
		cin >> y_or_n;

	}
	while((y_or_n != 'N')&&(y_or_n !='n'))
	{
		cout << "Choice element:";
		cin >> del_item;
		check = dele(&root, del_item);
		if(check)
			print(root);
		else
			cout << del_item << " is not in the tree" << endl;
		cout << "Delete element?(Y/N):";
		cin >> y_or_n;
	}
}




