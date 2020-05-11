/*
									ASSIGNMENT NO - 03

Assignment Statement:- For a given expression e.g. a-b*c-d/e+f construct inorder sequence and traverse it using postorder traversal
					   ( Non- recursive ). Change a tree so that the roles of left and right pointers are swapped at every node.

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include<stack>
using namespace std;

class exptree_node
{
	public :
	char cdata;
	exptree_node *left,*right;
};


int top = -1;
exptree_node *a[50];
void push(exptree_node *tree)//push elements in stack
{
   top++;
   a[top] = tree;
}
exptree_node *pop()
{
   top--;
   return (a[top + 1]);
}

class exptree
{

	public :
	exptree_node *head;

	exptree()
	{
		head = NULL;
	}

	void insert(char *suffix);
	void inorder(exptree_node *temp);
};

int check(char inputch)//check the symbol whether it is an operator or an operand.
{
   if (inputch == '+' || inputch == '-' || inputch == '*' || inputch == '/')
      return (-1);
   else if (inputch >= 'A' || inputch <= 'Z')
      return (1);
   else if (inputch >= 'a' || inputch <= 'z')
      return (1);
   else
      return (-100);
}

void exptree :: insert(char *suffix)
{
	exptree_node *newl,*l,*r;
	char s;
	s = suffix[0];
	 int flag;
   	for (int i = 1; s!= 0; i++)
   	{
      flag = check(s);
      if (flag == 1)
      {
         newl = new exptree_node;
         newl->cdata = s;
         newl->left = NULL;
         newl->right = NULL;
         push(newl);
      }
      else
      {
         r = pop();
         l = pop();
         newl = new exptree_node;
         newl->cdata = s;
         newl->left = l;
         newl->right = r;
         push(newl);
      }
      s = suffix[i];
     }
}

void exptree :: inorder(exptree_node *temp)
{
   if (temp != NULL)
   {
      inorder(temp->left);
      cout << temp->cdata;
      inorder(temp->right);
   }
}

int main()
{
	exptree e;
	char exp[50],i;
	cout<<"Enter expression : ";
	for(i=0;i<5;i++)
	{
		cin>>exp[i];
	}
		e.insert(exp);

	cout<<"\nInorder : ";
	e.inorder(a[top]);
}
/*
    OUTPUT
    
Enter expression : ab*c-

Inorder : a*b-c
*/
