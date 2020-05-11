/*
                                    ASSIGNMENT NO - 05

Assignment Statement:- Convert a given Binary Tree into Threaded Binary Tree.Analyze space and time complexity of Algorithm.

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
using namespace std;

class thread_node
{
	public:
	int data;
	thread_node *left,*right;
	int lbit,rbit;
};

class TBT
{

	public:
	char ch;
	int flag;
	thread_node *head,*root;
	TBT()
	{
		head=new thread_node;
		head->data=0;
		head->left=head->right=head;
		head->lbit=0;
		head->rbit=1;
		root=NULL;
	}
	void create();
	void insert();
	void inorder();
	void preorder();
};

void TBT :: create()
{
	do
	{
		insert();
		cout<<"\n\tWANT TO CONTINUE : ";
		cin>>ch;
	}while(ch=='Y'|| ch=='y');
}

void TBT :: insert()
{
	thread_node *temp,*curr;
	curr=new thread_node;
		cout<<"\n\tENTER NODE DATA : ";
		cin>>curr->data;
		curr->lbit=curr->rbit=1;
		if(root==NULL)
		{
			root=curr;
			root->left=root->right=head;
			head->left=root;
			head->lbit=0;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->data < temp->data)
				{
					if(temp->lbit==1)
					{
						curr->left=temp->left;
						temp->left=curr;
						temp->lbit=0;
						curr->right=temp;
						break;
					}
					else
						temp=temp->left;
				}
				else
				{
					if(temp->rbit==1)
					{
						curr->right=temp->right;
						temp->right=curr;
						temp->rbit=0;
						curr->left=temp;
						break;
					}
					else
						temp=temp->right;
				}
			}
		}
		cout<<"\n\t !!! ELEMENT ADDED SUCCESSFULLY !!!";
}

void TBT :: inorder()
{
	cout<<"\n\t INORDER : ";
	thread_node *temp;
	flag=0;
	temp=root;
	while(temp!=head)
	{
		if(temp->lbit==0 && flag==0)
			temp=temp->left;
		else
		{
			cout<<temp->data<<" ";
			if(temp->rbit==0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		}
	}
	cout<<endl;
}

void TBT :: preorder()
{
	cout<<"\n\t PREORDER : ";
	thread_node *temp=root;
	flag=0;
	while(temp!=head)
	{
		if(flag==0)
			cout<<temp->data<<" ";
		if(temp->lbit == 0 && flag == 0)
			temp=temp->left;
		else
		{
			if(temp->rbit == 0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		}
	}
	cout<<endl;
}

int main()
{
	TBT t;
	int choice;
	do
	{
		cout<<"\n\n------> MENU <------";
		cout<<"\n1] Create TBT";
		cout<<"\n2] Insert a node in TBT";
		cout<<"\n3] Inorder traversal of TBT";
		cout<<"\n4] preorder traversal of TBT";
		cout<<"\n5] Exit";
		cout<<"\nENTER CHOICE : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					t.create();
					break;
			case 2:
					t.insert();
					break;
			case 3:
					t.inorder();
					break;
			case 4:
					t.preorder();
					break;
			case 5:
					break;
			default:
					cout<<"\n\t !!! INVALID CHOICE !!!";
		}
	}while(choice != 5);
}

/*
	OUTPUT

------> MENU <------
1] Create TBT
2] Insert a node in TBT
3] Inorder traversal of TBT
4] preorder traversal of TBT
5] Exit
ENTER CHOICE : 1

	ENTER NODE DATA : 50

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : y

	ENTER NODE DATA : 25

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : y

	ENTER NODE DATA : 12

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : y

	ENTER NODE DATA : 56

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : y

	ENTER NODE DATA : 78

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : y

	ENTER NODE DATA : 54

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : y

	ENTER NODE DATA : 40

	 !!! ELEMENT ADDED SUCCESSFULLY !!!
	WANT TO CONTINUE : n


------> MENU <------
1] Create TBT
2] Insert a node in TBT
3] Inorder traversal of TBT
4] preorder traversal of TBT
5] Exit
ENTER CHOICE : 2

	ENTER NODE DATA : 89

	 !!! ELEMENT ADDED SUCCESSFULLY !!!

------> MENU <------
1] Create TBT
2] Insert a node in TBT
3] Inorder traversal of TBT
4] preorder traversal of TBT
5] Exit
ENTER CHOICE : 3

	 INORDER : 12 25 40 50 54 56 78 89 


------> MENU <------
1] Create TBT
2] Insert a node in TBT
3] Inorder traversal of TBT
4] preorder traversal of TBT
5] Exit
ENTER CHOICE : 4

	 PREORDER : 50 25 12 40 56 54 78 89 


------> MENU <------
1] Create TBT
2] Insert a node in TBT
3] Inorder traversal of TBT
4] preorder traversal of TBT
5] Exit
ENTER CHOICE : 9

	 !!! INVALID CHOICE !!!

------> MENU <------
1] Create TBT
2] Insert a node in TBT
3] Inorder traversal of TBT
4] preorder traversal of TBT
5] Exit
ENTER CHOICE : 5

*/
