/*
                                    ASSIGNMENT NO - 08

Assignment Statement:- Impement all the functions of dictionary( ADT ) using hashing data: set of(key,value)pairs,keys are mapped to
					   values,key must be comparable,key must be unique.Standard operation: Insert(key,value),find(key),Delete(key).

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include<string.h>
#include<unistd.h>
#define MAX 10
using namespace std;

class dictionary
{
	string name[MAX],meaning[MAX];
	int chain[MAX];

	public:
			dictionary()
			{
				for(int i=0;i<MAX;i++)
				{
					name[i] = "\0";
					meaning[i] = "\0";
					chain[i] = -1;
				}
			}

			void hashingfun(string h, string t);
			void findfun(string h);
			void delfun(string h);

			void display()
			{
				for(int i=0;i<MAX;i++)
				{
					cout<<"\n"<<i<<"\t"<<name[i]<<"\t"<<meaning[i]<<"\t"<<chain[i];
				}
			}
};

void dictionary :: hashingfun(string h, string t)
{
	int ascii[10],cnt=0,homeadd=0,j=0;
	for(int i=0;i<h.size();i++)
	{
		if(i%2 == 0)
		{
			ascii[j] = h[i];
			j++;
			cnt++;
		}
	}

	for(int i=0;i<cnt;i++)
	{
		homeadd += ascii[i];
	}

	while(homeadd>MAX)
	{
		homeadd %= 10;
	}

	while(homeadd < MAX)
	{
		if(name[homeadd] == "\0")
		{
			name[homeadd] = h;
			meaning[homeadd] = t;
			break;
		}
		else if(name[homeadd] == h)
		{
			cout<<"\n\t !!! KEYWORD ALREADY EXIST !!!";
			break;
		}
		homeadd += 1;
		chain[homeadd-1] = homeadd;
	}
}

void dictionary :: findfun(string h)
{
	int ascii[10],cnt=0,homeadd=0,flag=0,j=0;
	for(int i=0;i<h.size();i++)
	{
		if(i%2 == 0)
		{
			ascii[j] = h[i];
			j++;
			cnt++;
		}
	}

	for(int i=0;i<cnt;i++)
	{
		homeadd += ascii[i];
	}

	while(homeadd>MAX)
	{
		homeadd %= 10;
	}

	while(1)
	{
		if(name[homeadd] == h)
		{
			cout<<"\n\t!!! KEYWORD FOUND !!!";
			cout<<"\nTHE KEYWORD :- "<<name[homeadd]<<"\nTHE MEANING :- "<<meaning[homeadd];
			flag = 1;
			break;
		}
		else if(chain[homeadd] == -1)
			break;
		else
		{
			homeadd = chain[homeadd];
		}
	}

	if(flag==0)
		cout<<"\n\t !!! KEYWORD NOT FOUND !!!";
}

void dictionary :: delfun(string h)
{
	char temp[10];
	int ascii[10],cnt=0,homeadd=0,flag=0,j=0;
	for(int i=0;i<h.size();i++)
	{
		if(i%2 == 0)
		{
			ascii[j] = h[i];
			j++;
			cnt++;
		}
	}

	for(int i=0;i<cnt;i++)
	{
		homeadd += ascii[i];
	}

	while(homeadd>MAX)
	{
		homeadd %= 10;
	}

	while(1)
	{
		if(name[homeadd] == h)
		{
			cout<<"\n\t !!! KEYWORD DELETED SUCCESSFULLY !!!";
			name[homeadd] = "\0";
			meaning[homeadd] = "\0";
			flag = 1;
			break;
		}
		else if(chain[homeadd] == -1)
			break;
		else
		{
			homeadd = chain[homeadd];
		}
	}

	if(flag==0)
		cout<<"\n\t !!! KEYWORD NOT FOUND !!!";
}


int main()
{
	dictionary d;
	string name, meaning;
	char ch;
	int choice;
	cout<<"\n\tADD KEYWORDS TO DICTIONARY";
	do
	{
					cout<<"\nENTER KEYWORD : ";
					cin>>name;
					cout<<"ENTER MEANING : ";
					cin>>meaning;
					d.hashingfun(name , meaning);
					cout<<"\nWANT TO ENTER ANOTHER (Y/N) : ";
					cin>>ch;
	}while(ch=='Y' || ch=='y');

	cout<<"\nPLEASE WAIT...";
	cout<<"\n";
	do
	{
		sleep(3);
		system("clear");
		cout<<"\n\t\t |=======================|";
		cout<<"\n\t\t ||      DICTIONARY     ||";
		cout<<"\n\t\t |=======================|";
		cout<<"\n\t\t |                       |";
		cout<<"\n\t\t |  1. ADD KEYWORD       |";
		cout<<"\n\t\t |  2. SEARCH KEYWORD    |";
		cout<<"\n\t\t |  3. DELETE KEYWORD    |";
		cout<<"\n\t\t |  4. EXIT              |";
		cout<<"\n\t\t |                       |";
		cout<<"\n\t\t |=======================|";

		cout<<"\n\n\tENTER YOUR CHOICE : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					cout<<"\nENTER KEYWORD : ";
					cin>>name;
					cout<<"ENTER MEANING : ";
					cin>>meaning;
					d.hashingfun(name , meaning);
					break;

			case 2:
					cout<<"\nENTER KEYWORD : ";
					cin>>name;
					d.findfun(name);
					break;

			case 3:
					cout<<"\nENTER KEYWORD : ";
					cin>>name;
					d.delfun(name);
					break;

			case 4:
					break;

			default:
					cout<<"\n\t!!! INVALID CHOCIE !!!";
		}

		if(choice!=4)
			cout<<"\nPLEASE WAIT...";

			cout<<"\n";
	}while(choice!=4);
	cout<<"\n";
	system("clear");
	cout<<"\n\n\n\n\n\n\nEXITING APPLICATION....";
	cout<<"\n";
	sleep(2);
	system("clear");
}

/*
	OUTPUT
	ADD KEYWORDS TO DICTIONARY
ENTER KEYWORD : remark
ENTER MEANING : mention

WANT TO ENTER ANOTHER (Y/N) : y

ENTER KEYWORD : pulchritudinous
ENTER MEANING : beautiful

WANT TO ENTER ANOTHER (Y/N) : n

		 |=======================|
		 ||      DICTIONARY     ||
		 |=======================|
		 |                       |
		 |  1. ADD KEYWORD       |
		 |  2. SEARCH KEYWORD    |
		 |  3. DELETE KEYWORD    |
		 |  4. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 2

ENTER KEYWORD : pulchritudinous

	!!! KEYWORD FOUND !!!
THE KEYWORD :- pulchritudinous
THE MEANING :- beautiful

		 |=======================|
		 ||      DICTIONARY     ||
		 |=======================|
		 |                       |
		 |  1. ADD KEYWORD       |
		 |  2. SEARCH KEYWORD    |
		 |  3. DELETE KEYWORD    |
		 |  4. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 3

ENTER KEYWORD : remark

	 !!! KEYWORD DELETED SUCCESSFULLY !!!

		 |=======================|
		 ||      DICTIONARY     ||
		 |=======================|
		 |                       |
		 |  1. ADD KEYWORD       |
		 |  2. SEARCH KEYWORD    |
		 |  3. DELETE KEYWORD    |
		 |  4. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 2

ENTER KEYWORD : pulchritudinous

	!!! KEYWORD FOUND !!!
THE KEYWORD :- pulchritudinous
THE MEANING :- beautiful

		 |=======================|
		 ||      DICTIONARY     ||
		 |=======================|
		 |                       |
		 |  1. ADD KEYWORD       |
		 |  2. SEARCH KEYWORD    |
		 |  3. DELETE KEYWORD    |
		 |  4. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 2

ENTER KEYWORD : remark

	 !!! KEYWORD NOT FOUND !!!

		 |=======================|
		 ||      DICTIONARY     ||
		 |=======================|
		 |                       |
		 |  1. ADD KEYWORD       |
		 |  2. SEARCH KEYWORD    |
		 |  3. DELETE KEYWORD    |
		 |  4. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 4

*/
