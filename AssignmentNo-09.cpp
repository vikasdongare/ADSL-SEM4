/*
                                    ASSIGNMENT NO - 09

Assignment Statement:- A Dictionary stores keyword and its meaning.Provid facility for adding new keyword,deleting keyword,updating value of
			           any entry.Provid facility to display data sort in ascending/descending order.Also find how many maximum comparision
			           are required to finding any keyword.Use height balance tree and find the complexity for finding a keyword.
Name   :- Vikas Laxman Donagare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include<string.h>
#define max 20
using namespace std;
class AVLnode
{
	public:
			char keyword[20],meaning[20];
			AVLnode *left,*right;
			int ht;
};
class AVLtree
{
	public:
			AVLnode *root;
			AVLtree()
			{
				root=NULL;
			}
			AVLnode *rotate_right(AVLnode *x);
			AVLnode *rotate_left(AVLnode *x);
			AVLnode *LL(AVLnode *x);
			AVLnode *LR(AVLnode *x);
			AVLnode *RR(AVLnode *x);
			AVLnode *RL(AVLnode *x);
			int height(AVLnode *T);
			AVLnode *insert(AVLnode *root,char newkey[20],char mean[20]);
			void inorder_recurssive(AVLnode *root);
			int BF(AVLnode *T);
};

AVLnode *AVLtree::rotate_right(AVLnode *x)
{
	AVLnode *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
}

AVLnode *AVLtree::rotate_left(AVLnode *x)
{
	AVLnode *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
}

AVLnode *AVLtree::LL(AVLnode *T)
{
	cout<<"\n\tIn LL rotation \n";
	T=rotate_right(T);
	return T;
}

AVLnode *AVLtree::RR(AVLnode *T)
{
	cout<<"\n\tIn RR Rotation \n";
	T=rotate_right(T);
	return T;
}

int AVLtree::BF(AVLnode *T)
{
	int lh,rh;
		if(T==NULL)
			return 0;
		else
		{
			if(T->left==NULL)
				lh=0;
			else
				lh=1+T->left->ht;
			if(T->right==NULL)
				rh=0;
			else
				rh=1+T->right->ht;
		}
		return (lh-rh);
}

int AVLtree::height(AVLnode *T)
{
	int hl,hr;
	if(T==NULL)
		return 0;
	if(T->left==NULL && T->right==NULL)
		return 0;
	hl=height(T->left);
	hr=height(T->right);
	if(hl<hr)
		return hr+1;
	else
		return hl+1;
}

AVLnode *AVLtree::RL(AVLnode *T)
{
	cout<<"\n\tIn RL rotation\n";
	T->right=rotate_right(T->right);
	T=rotate_left(T);
	return T;
}

AVLnode *AVLtree::LR(AVLnode *T)
{
	cout<<"\n\tIn LR rotation \n";
	T->left=rotate_left(T->left);
	T=rotate_right(T);
	return T;
}

AVLnode *AVLtree::insert(AVLnode *root,char newkey[20],char mean[20])
{
	AVLnode *curr;
	int lh,rh;
	if(root==NULL)
	{
		curr=new AVLnode;
		strcpy(curr->keyword,newkey);
		strcpy(curr->meaning,mean);
		curr->ht=0;
		curr->left=NULL;
		curr->right=NULL;
		root=curr;
		cout<<root->keyword;
	}
	else
	{
		if(strcmp(newkey,root->keyword)<0)
		{
			root->left=insert(root->left,newkey,mean);
			if(BF(root)==2)
			{
				if(strcmp(newkey,root->left->keyword)<0)
				{
					root=LL(root);
				}
				else
				{
					root=LR(root);
				}
			}
		}
		else
		{
			if(strcmp(newkey,root->keyword)>0)
			{
				root->right=insert(root->right,newkey,mean);
				if(BF(root)==-2)
				{
					if(strcmp(newkey,root->right->keyword)>0)
					{
						root=RR(root);
					}
					else
					{
						root=LR(root);
					}
				}
			}
			else
				cout<<"\n\tDuplicate";
		}
		root->ht=height(root);
		return root;
	}
}

void AVLtree::inorder_recurssive(AVLnode *root)
{
			if(root!=NULL)
			{
			    inorder_recurssive(root->left);
				cout<<"\nKEYWORD : "<<root->keyword;
				cout<<"MEANING : "<<root->meaning;
				inorder_recurssive(root->right);
			}
}

int main()
{
	int choice;
	AVLtree a;
	AVLnode *root=NULL;
	char keyword[20],meaning[20],ch;
	do
	{
		cout<<"\n----> MENU <----";
		cout<<"\n 1. INSERT ";
		cout<<"\n 2. DISPLAY ";
		cout<<"\n 3. EXIT ";
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					do
					{

						cout<<"\nENTER KEYWORD : ";
						cin>>keyword;
						cout<<"ENTER MEANING : ";
						cin>>meaning;
						root=a.insert(root,keyword,meaning);
						cout<<"\nWANT TO ENTER ANOTHER(Y/N) : ";
						cin>>ch;
					}while(ch == 'Y' | ch == 'y');
					break;

			case 2:
					cout<<"\nDISPLAYING....";
					a.inorder_recurssive(root);
					break;

			case 3:
					break;

			default:
					cout<<"\n!!! INVALID CHOICE !!!";
		}
	}while(choice!=3);

	return 0;
}
