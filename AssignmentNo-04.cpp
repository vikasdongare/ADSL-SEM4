/*
                                    ASSIGNMENT NO - 04
Assignment Statement:- A Dictionary stores keyword and its meaning.Provid facility for adding new keyword,deleting keyword,updating value
                       of any entry.Provid facility to display data sort in ascending/descending order.Also find how many maximum
                       comparision are required to finding any keyword.Use Binary Search Tree for impelentation.

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
using namespace std;

class dict_node
{
    public:
    string skeyword;
    int imeaning_count;
    string meaning[100];
    dict_node *left,*right;
};

class dict
{
    int iflag=0;
    public:
    dict_node *root;


        dict()
        {
            root=NULL;
            iflag=0;
        }

        void create();
        void insert();
        void display();
        dict_node* search_recurssive(dict_node *temp, string skey);
        void inorder(dict_node *temp);
};

void dict :: create()
{
        root=new dict_node;
        cout<<"\n\t\tENTER KEYWORD : ";
        cin>>root->skeyword;
        cout<<"\t\tENTER NUMBER MEANINGS : ";
        cin>>root->imeaning_count;

        for(int i=0;i<root->imeaning_count;i++)
        {
            cout<<"\t\tENTER MEANING "<<i+1<<" : ";
            cin>>root->meaning[i];
        }
        root->left=NULL;
        root->right=NULL;
        cout<<"\n\t  !!! KEYWORD ADDED SUCCESFULLY !!! ";

}

void dict :: insert()
{
    dict_node *temp,*curr;
    if(root==NULL)
        create();

    temp=root;
    string skeyword;
    int imeaning_count;
    string meaning[100];
    cout<<"\n\t\tENTER KEYWORD : ";
    cin>>skeyword;

    while(1)
    {
        if(skeyword<temp->skeyword)
        {
            if(temp->left==NULL)
            {
                curr=new dict_node;
                curr->left=NULL;
                curr->right=NULL;
                curr->skeyword=skeyword;

                cout<<"\t\tENTER NUMBER MEANINGS : ";
                cin>>curr->imeaning_count;
                for(int i=0;i<curr->imeaning_count;i++)
                {
                    cout<<"\t\tENTER MEANING "<<i+1<<" : ";
                    cin>>curr->meaning[i];
                }

                temp->left=curr;
                cout<<"\n\t  !!! KEYWORD ADDED SUCCESFULLY !!! ";
                return;
            }
            else
                temp=temp->left;
        }
        else if(skeyword>temp->skeyword)
        {
            if(temp->right==NULL)
            {
                curr=new dict_node;
                curr->left=NULL;
                curr->right=NULL;
                curr->skeyword=skeyword;


                cout<<"\t\tENTER NUMBER MEANINGS : ";
                cin>>curr->imeaning_count;
                for(int i=0;i<curr->imeaning_count;i++)
                {
                    cout<<"\t\tENTER MEANING "<<i+1<<" : ";
                    cin>>curr->meaning[i];
                }

                temp->right=curr;
                cout<<"\n\t  !!! KEYWORD ADDED SUCCESFULLY !!! ";
                return;
            }
            else
                temp=temp->right;
        }
        else
        {
            char choice;
            cout<<"\n\t  !!! KEYWORD ALREADY EXIST !!!";
            cout<<"\n\t\t ADD ANOTHER MEANING TO THE KEYWORD (Y/N) : ";
            cin>>choice;

            if(choice == 'Y' || choice == 'y')
            {
                cout<<"\n\t\t ENTER MEANING : ";
                cin>>temp->meaning[temp->imeaning_count];
                temp->imeaning_count += 1;
                return;
            }
        }
    }
}

dict_node* dict ::search_recurssive(dict_node *temp, string skey)
{
        if(temp!=NULL)
        {
            if(temp->skeyword > skey)
            {
                search_recurssive(temp->left,skey);
            }
            else if(temp->skeyword < skey)
            {
                search_recurssive(temp->right,skey);
            }
            else
            {
                cout<<"\n\t\t  !!! ELEMENT FOUND !!!";
                cout<<"\n\t\tTHE GIVEN KEYWORD : "<<temp->skeyword;
                cout<<"\n\t\tMEANING           : ";
                for(int i=0;i<temp->imeaning_count;i++)
                {
                    cout<<i+1<<". "<<temp->meaning[i];
                    cout<<"\n\t\t\t\t    ";
                }
                return temp;
            }
        }
        else
        {
            return NULL;
        }
}

void dict::inorder(dict_node *temp)
{
			if(temp!=NULL)
			{
			    inorder(temp->left);
				cout<<temp->skeyword<<" ";
				inorder(temp->right);
			}
}

int main()
{
        dict d;
        int ichoice;
        string skey;

        do
        {

            cout<<"\n\t====================================\t";
            cout<<"\n\n\t\t  -----> MENU <----- ";
            cout<<"\n\t\t 1. CREATE DICTIONARY ";
            cout<<"\n\t\t 2. ADD NEW WORD ";
            cout<<"\n\t\t 3. SEARCH A WORD ";
            cout<<"\n\t\t 4. EXIT ";
            cout<<"\n ENTER YOUR CHOICE : ";
            cin>>ichoice;
            cout<<"\n\t====================================\t";

            switch(ichoice)
            {
            case 1:
                    d.create();
                    break;

            case 2:
                    d.insert();
                    break;

            case 3:
                    cout<<"\n\t ENTER KEYWORD TO SEARCH : ";
                    cin>>skey;
                    if(d.search_recurssive(d.root,skey)== NULL)
                    {
                        cout<<"\n\t\t  !!! ELEMENT NOT FOUND !!!";
                    }
                    break;

            case 4:
                    break;

            default:
                    cout<<"\n\t  !!! INVALID CHOICE !!!";

            }
        }while(ichoice!=4);

}

/*
	OUTPUT

	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 1

	====================================	
		ENTER KEYWORD : declarative
		ENTER NUMBER MEANINGS : 1
		ENTER MEANING 1 : adjective

	  !!! KEYWORD ADDED SUCCESFULLY !!! 
	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 2

	====================================	
		ENTER KEYWORD : remark
		ENTER NUMBER MEANINGS : 1
		ENTER MEANING 1 : mention

	  !!! KEYWORD ADDED SUCCESFULLY !!! 
	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 2

	====================================	
		ENTER KEYWORD : pulchritudinous
		ENTER NUMBER MEANINGS : 2
		ENTER MEANING 1 : adjective
		ENTER MEANING 2 : beautiful

	  !!! KEYWORD ADDED SUCCESFULLY !!! 
	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 3

	====================================	
	 ENTER KEYWORD TO SEARCH : declarative

		  !!! ELEMENT FOUND !!!
		THE GIVEN KEYWORD : declarative
		MEANING           : 1. adjective
				    
	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 3

	====================================	
	 ENTER KEYWORD TO SEARCH : pulchritudinous

		  !!! ELEMENT FOUND !!!
		THE GIVEN KEYWORD : pulchritudinous
		MEANING           : 1. adjective
				    2. beautiful
				    
	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 5

	====================================	
	  !!! INVALID CHOICE !!!
	====================================	

		  -----> MENU <----- 
		 1. CREATE DICTIONARY 
		 2. ADD NEW WORD 
		 3. SEARCH A WORD 
		 4. EXIT 
 ENTER YOUR CHOICE : 4

	====================================	
*/

