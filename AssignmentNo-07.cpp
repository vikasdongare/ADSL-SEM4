/*
                                    ASSIGNMENT NO - 07

Assignment Statement:- Consider telephone book database of N clients.Make use of hash table impelementation to quickly look up client's
				       telephone number.

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<iomanip>
#define MAX 10
using namespace std;

class directory
{
	string name[MAX];
	long int tele[MAX];
	int chain[MAX];

	public:
			directory()
			{
				for(int i=0;i<MAX;i++)
				{
					name[i] = "\0";
					tele[i] = 0;
					chain[i] = -1;
				}
			}

			void hashingfun(string h, long int t);
			void findfun(string h);
			void delfun(string h);

			void display()
			{
				cout<<"\n"<<setw(5)<<"POS"<<setw(10)<<"NAME"<<setw(15)<<"TELEPHONE"<<setw(10)<<"CHAIN";
				for(int i=0;i<MAX;i++)
				{
					cout<<"\n"<<setw(5)<<i<<setw(15-name[i].size())<<name[i];
					cout<<setw(12);
					if(tele[i]!=0)
						cout<<tele[i];

					cout<<setw(8)<<"\t"<<chain[i];
				}
			}
};

void directory :: hashingfun(string h, long int t)
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
			tele[homeadd] = t;
			break;
		}
		else if(name[homeadd] == h)
		{
			cout<<"\n\t !!! CONTACT NAME ALREADY EXIST !!!";
			break;
		}
		homeadd += 1;
		chain[homeadd-1] = homeadd;
	}
}

void directory :: findfun(string h)
{
	int ascii[10],j=0,cnt=0,homeadd=0,flag=0;
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
			cout<<"\n\t!!! CONTACT FOUND !!!";
			cout<<"\n"<<name[homeadd]<<"\t"<<tele[homeadd];
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
		cout<<"\n\t !!! CONTACT NOT FOUND !!!";
}

void directory :: delfun(string h)
{
	int ascii[10],j=0,cnt=0,homeadd=0,flag=0;
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
			cout<<"\n\t !!! CONTACT DELETED SUCCESSFULLY !!!";
			name[homeadd] = "\0";
			tele[homeadd] = 0;
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
		cout<<"\n\t !!! CONTACT NOT FOUND !!!";
}


int main()
{
	directory d;
	string name;
	long int tele;
	char ch;
	int choice;
	cout<<"\n\tADD CONTACTS TO DIRECTORY";
	do
	{
					cout<<"\nENTER CONTACT NAME : ";
					cin>>name;
					cout<<"ENTER TELEPHONE NUMBER : ";
					cin>>tele;
					d.hashingfun(name , tele);
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
		cout<<"\n\t\t || TELEPHONE DIRECTORY ||";
		cout<<"\n\t\t |=======================|";
		cout<<"\n\t\t |                       |";
		cout<<"\n\t\t |  1. ADD CONTACTS      |";
		cout<<"\n\t\t |  2. SEARCH CONTACT    |";
		cout<<"\n\t\t |  3. DELETE CONTACT    |";
		cout<<"\n\t\t |  4. DISPLAY           |";
		cout<<"\n\t\t |  5. EXIT              |";
		cout<<"\n\t\t |                       |";
		cout<<"\n\t\t |=======================|";

		cout<<"\n\n\tENTER YOUR CHOICE : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					cout<<"\nENTER CONTACT NAME : ";
					cin>>name;
					cout<<"ENTER TELEPHONE NUMBER : ";
					cin>>tele;
					d.hashingfun(name , tele);
					break;

			case 2:
					cout<<"\nENTER CONTACT NAME : ";
					cin>>name;
					d.findfun(name);
					break;

			case 3:
					cout<<"\nENTER CONTACT NAME : ";
					cin>>name;
					d.delfun(name);
					break;

			case 4:
					d.display();
					break;
			case 5:
					break;

			default:
					cout<<"\n\t!!! INVALID CHOCIE !!!";
		}

		if(choice!=5)
			cout<<"\nPLEASE WAIT...";

			cout<<"\n";
	}while(choice!=5);
	cout<<"\n";
	system("clear");
	cout<<"\n\n\n\n\t\t\tEXITING APPLICATION....";
	cout<<"\n";
	sleep(2);
	system("clear");
}

/*
	OUTPUT
	
	ADD CONTACTS TO DIRECTORY
ENTER CONTACT NAME : Mayur
ENTER TELEPHONE NUMBER : 8421114579

WANT TO ENTER ANOTHER (Y/N) : n


		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 1

ENTER CONTACT NAME : Sagar
ENTER TELEPHONE NUMBER : 9822187359

PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 1

ENTER CONTACT NAME : Vikas
ENTER TELEPHONE NUMBER : 9975093783

PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 1

ENTER CONTACT NAME : Akash
ENTER TELEPHONE NUMBER : 8308089347

PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 2

ENTER CONTACT NAME : Vikas

	!!! CONTACT FOUND !!!
Vikas	9975093783
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 2

ENTER CONTACT NAME : Shreenik

	 !!! CONTACT NOT FOUND !!!
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 4

  POS      NAME      TELEPHONE     CHAIN
    0     Sagar  9822187359       	-1
    1                      			-1
    2     Mayur  8421114579       	-1
    3                      			-1
    4                      			-1
    5                      			-1
    6     Akash  8308089347       	-1
    7                      			-1
    8     Vikas  9975093783       	-1
    9                      			-1
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 3

ENTER CONTACT NAME : Vikas

	 !!! CONTACT DELETED SUCCESSFULLY !!!
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 4

  POS      NAME      TELEPHONE     CHAIN
    0     Sagar  9822187359       	-1
    1                      			-1
    2     Mayur  8421114579       	-1
    3                      			-1
    4                      			-1
    5                      			-1
    6     Akash  8308089347       	-1
    7                      			-1
    8                      			-1
    9                      			-1
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 3

ENTER CONTACT NAME : Shreenik

	 !!! CONTACT NOT FOUND !!!
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 4

  POS      NAME      TELEPHONE     CHAIN
    0     Sagar  9822187359       	-1
    1                      			-1
    2     Mayur  8421114579       	-1
    3                      			-1
    4                      			-1
    5                      			-1
    6     Akash  8308089347       	-1
    7                      			-1
    8                      			-1
    9                      			-1
PLEASE WAIT...

		 |=======================|
		 || TELEPHONE DIRECTORY ||
		 |=======================|
		 |                       |
		 |  1. ADD CONTACTS      |
		 |  2. SEARCH CONTACT    |
		 |  3. DELETE CONTACT    |
		 |  4. DISPLAY           |
		 |  5. EXIT              |
		 |                       |
		 |=======================|

	ENTER YOUR CHOICE : 5



EXITING APPLICATION....

*/
