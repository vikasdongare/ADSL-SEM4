/*
											ASSIGNMENT NO - 02

Assignment Statement:- Beginning with empty binary search tree,Construct binary search tree by inserting the values in the order given.
                       After construction a binary tree-
							1)Insert new node
							2)Find number of nodes in longest path
							3)Minimum data value found in the tree
							4)Search the value

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include"stack.cpp"
using namespace std;

class tree_node
{
public:
        int idata;
        tree_node *lchild,*rchild;
};

class tree
{
public:
        tree_node *root;

        tree()
        {
            root=NULL;
        }

        void create();
        void insert();
        
        void inorder_recurssive(tree_node *temp);
        void inorder_nonrecurssive(tree_node *temp);
        void preorder_recurssive(tree_node *temp);
        void preorder_nonrecurssive(tree_node *temp);
        void postorder_recurssive(tree_node *temp);
        void postorder_nonrecurssive(tree_node *temp);
        int search_recurssive(tree_node *temp, int ikey);
        void search_nonrecurssive(tree_node *temp, int ikey);
        void maximum_value(tree_node *temp);
        void minimum_value(tree_node *temp);
};

void tree::create()
{
			root= new tree_node();
			cout<<"\n\tEnter element at root : ";
			cin>>root->idata;
			root->lchild=NULL;
			root->rchild=NULL;
			cout<<"\n\t\t!!! Root created succesfully !!!\n";
}

void tree::insert()
{
    tree_node *temp,*p;
    if(root==NULL)
        create();
    temp=root;
    int d;
    cout<<"\n\tEnter Number : ";
    cin>>d;
    while(1)
    {
        if(d<temp->idata)
        {
            if(temp->lchild==NULL)
            {
                p=new tree_node;
                p->lchild=NULL;
                p->rchild=NULL;
                p->idata=d;
                temp->lchild=p;
                cout<<"\n\t\t!!! Element Added succesfully !!!\n";
                return;
            }
            else
                temp=temp->lchild;
        }
        else if(d>temp->idata)
        {
            if(temp->rchild==NULL)
            {
                p=new tree_node;
                p->lchild=NULL;
                p->rchild=NULL;
                p->idata=d;
                temp->rchild=p;
                cout<<"\n\t\t!!! Element Added succesfully !!!\n";
                return;
            }
            else
                temp=temp->rchild;
        }
        else if(d==temp->idata)
        {
            cout<<"\n\t!!! DATA IS ALREADY ADDED !!!";
        }

    }
}

void tree::inorder_recurssive(tree_node *temp)
{
			if(temp!=NULL)
			{
			    inorder_recurssive(temp->lchild);
				cout<<temp->idata<<" ";
				inorder_recurssive(temp->rchild);
			}
}

void tree::inorder_nonrecurssive(tree_node *temp)
{
    stack<tree_node*>s;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->lchild;
        }

        if(s.isempty())
            return;

        temp=s.pop();
        cout<<temp->idata<<" ";
        temp=temp->rchild;
    }
}

void tree::preorder_recurssive(tree_node *temp)
{
			if(temp!=NULL)
			{
				cout<<temp->idata<<" ";
			    preorder_recurssive(temp->lchild);
				preorder_recurssive(temp->rchild);
			}
}

void tree::preorder_nonrecurssive(tree_node *temp)
{
    stack<tree_node*>s;
    while(1)
    {
        while(temp!=NULL)
        {
            cout<<temp->idata<<" ";
            s.push(temp);
            temp=temp->lchild;
        }

        if(s.isempty())
            return;

        temp=s.pop();
        temp=temp->rchild;
    }
}

void tree::postorder_recurssive(tree_node *temp)
{
			if(temp!=NULL)
			{
			    postorder_recurssive(temp->lchild);
				postorder_recurssive(temp->rchild);
				cout<<temp->idata<<" ";
			}
}

void tree::postorder_nonrecurssive(tree_node *temp)
{
    stack<tree_node*>s;
    stack<char>s1;
    char flag;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            cout<<s.pop();
            s1.push('L');
            temp=temp->lchild;
        }

        if(s.isempty())
            return;

        else
        {
            temp=s.pop();
            flag=s1.pop();
            if(flag=='R')
            {
                cout<<temp->idata<<" ";
                temp=NULL;
            }
            else
            {
                s.push(temp);
                s1.push('R');
                temp=temp->rchild;
            }
        }
    }
}

int tree ::search_recurssive(tree_node *temp, int ikey)
{
    if(temp != NULL)
    {
        if(temp->idata > ikey)
        {
            search_recurssive(temp->lchild,ikey);
        }
        else if(temp->idata < ikey)
        {
            search_recurssive(temp->rchild,ikey);
        }
        else
        {
            cout<<"\n\t!!! ELEMENT FOUND !!!";
            return 0;
        }
    }
    return 1;
}

void tree::search_nonrecurssive(tree_node *temp,int ikey)
{
    int iflag=0;
    while(temp!=NULL)
    {
        if(temp->idata > ikey)
        {
            temp=temp->lchild;
        }
        else if(temp->idata < ikey)
        {
            temp=temp->rchild;
        }
        else
        {
            cout<<"\n\t!!! ELEMENT FOUND !!!";
            iflag=1;
            return;
        }
    }
    if(iflag==0 || temp==NULL)
    {
        cout<<"\n\t!!! ELEMENT NOT FOUND !!!";
    }
}

void tree::minimum_value(tree_node *temp)
{
    while(temp->lchild!=NULL)
    {
        temp=temp->lchild;
    }
    cout<<"\n\tMINIMUM ELEMENT = "<<temp->idata;
}

void tree::maximum_value(tree_node *temp)
{
    while(temp->rchild!=NULL)
    {
        temp=temp->rchild;
    }
    cout<<"\n\tMAXIMUM ELEMENT = "<<temp->idata;
}

int main()
{
    tree t;
	int ich,ikey;
	int icount=0;
	do
    {
        cout<<"\n\t-------------------------------------";
	cout<<"\n\t\t      --> MENU <--";
	cout<<"\n\t  1.Create New Tree";
	cout<<"\n\t  2.Add Element to existing tree";
	cout<<"\n\t  3.Display tree in inorder (recurrsive function)";
	cout<<"\n\t  4.Display tree in inorder (non-recurrsive function)";
	cout<<"\n\t  5.Display tree in preorder (recurrsive function)";
	cout<<"\n\t  6.Display tree in preorder (non-recurrsive function)";
	cout<<"\n\t  7.Display tree in postorder(recurrsive function)";
	cout<<"\n\t  8.Display tree in postorder (non-recurrsive function)";
	cout<<"\n\t  9.Total count of elements in a tree";
	cout<<"\n\t  10.Search Element with recurssive ";
	cout<<"\n\t  11.Search Element with Non-recurssive ";
	cout<<"\n\t  12.Minimum value in a tree";
	cout<<"\n\t  13.Maximum value in a tree";
	cout<<"\n\t  14.Exit";
    cout<<"\n\t-------------------------------------";
	cout<<"\nENTER YOUR CHOICE : ";
	cin>>ich;

    cout<<"\n\t-------------------------------------\n";

	switch(ich)
	{
    case 1:
            t.create();
            break;

    case 2:
            t.insert();
            icount++;
            break;

    case 3:
            cout<<"\nDATA : ";
            t.inorder_recurssive(t.root);
            break;

    case 4:
            cout<<"\nDATA : ";
            t.inorder_nonrecurssive(t.root);
            break;

    case 5:
            cout<<"\nDATA : ";
            t.preorder_recurssive(t.root);
            break;

    case 6:
            cout<<"\nDATA : ";
            t.preorder_nonrecurssive(t.root);
            break;

    case 7:
            cout<<"\nDATA : ";
            t.postorder_recurssive(t.root);
            break;

    case 8:
            cout<<"\nDATA : ";
            //t.postorder_nonrecurssive(t.root);
            break;

    case 9:
            cout<<"\nTotal no of data : "<<icount+1;
            break;

    case 10:
            cout<<"\nEnter element to found :";
            cin>>ikey;
            if(t.search_recurssive(t.root,ikey)==1)
            {
                cout<<"\n\t!!! Element not found !!!";
            }
            break;

    case 11:
            cout<<"\nEnter element to found :";
            cin>>ikey;
            t.search_nonrecurssive(t.root,ikey);
            break;

    case 12:
            t.minimum_value(t.root);
            break;

    case 13:
            t.maximum_value(t.root);
            break;

    case 14:
            break;

    default:
            cout<<"\n\t !!! INVALID CHOICE !!!";
	}
    }while(ich!=14);
    return 0;
}

/*
    OUTPUT


        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 1

        -------------------------------------

        Enter element at root : 100

                !!! Root created succesfully !!!

        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 2

        -------------------------------------

        Enter Number : 50

                !!! Element Added succesfully !!!

        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 2

        -------------------------------------

        Enter Number : 125

                !!! Element Added succesfully !!!

        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 2

        -------------------------------------

        Enter Number : 25

                !!! Element Added succesfully !!!

        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 2

        -------------------------------------

        Enter Number : 75

                !!! Element Added succesfully !!!

        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 3

        -------------------------------------

DATA : 25 50 75 100 125
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 4

        -------------------------------------

DATA : 25 50 75 100 125
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 5

        -------------------------------------

DATA : 100 50 25 75 125
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 6

        -------------------------------------

DATA : 100 50 25 75 125
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 7

        -------------------------------------

DATA : 25 75 50 125 100
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 8

        -------------------------------------

DATA :  25 75 50 125 100
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 9

        -------------------------------------

Total no of data : 5
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 10

        -------------------------------------

Enter element to found :50

        !!! ELEMENT FOUND !!!
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 10

        -------------------------------------

Enter element to found :89

        !!! Element not found !!!
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 11

        -------------------------------------

Enter element to found :50

        !!! ELEMENT FOUND !!!
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 11

        -------------------------------------

Enter element to found :89

        !!! ELEMENT NOT FOUND !!!
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 12

        -------------------------------------

        MINIMUM ELEMENT = 25
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 13

        -------------------------------------

        MAXIMUM ELEMENT = 125
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 15

        -------------------------------------

         !!! INVALID CHOICE !!!
        -------------------------------------
                      --> MENU <--
          1.Create New Tree
          2.Add Element to existing tree
          3.Display tree in inorder (recurrsive function)
          4.Display tree in inorder (non-recurrsive function)
          5.Display tree in preorder (recurrsive function)
          6.Display tree in preorder (non-recurrsive function)
          7.Display tree in postorder(recurrsive function)
          8.Display tree in postorder (non-recurrsive function)
          9.Total count of elements in a tree
          10.Search Element with recurssive
          11.Search Element with Non-recurssive
          12.Minimum value in a tree
          13.Maximum value in a tree
          14.Exit
        -------------------------------------
ENTER YOUR CHOICE : 14

        -------------------------------------

Process returned 0 (0x0)   execution time : 56.735 s
Press any key to continue.
*/
