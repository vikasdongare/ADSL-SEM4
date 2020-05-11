/*
                                    ASSIGNMENT NO - 06 (Using Adjacency list)

Assignment Statement:- There are filght paths between cities.If there is filght between city A and city B then there is an edge between
					   cities.The cost of the edge can be the time thatflight takes to reach city B from city A, or the amount of Fuel
					   used for the journey.Represent this as a graph.The node can be represented by Airpot Name or name of the city.
					   Use Adjacency list representation of the graph or use Adjacency matrix representation of the graph.Justify the
					   storage representation used.

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

class flight_node
{
	public:
		string city;
		int time;
		flight_node *down,*next;
};

class flight
{
	public:
		string source_city,des_city;
		flight_node *root,*curr,*prev;

		flight()
		{
			root=NULL;
		}

		void city();
		void insert();
		void display();
		void pflight();
		void connected_city();
};

void flight :: city()
{
	curr=new flight_node;
	cout<<"ENTER NAME OF THE CITY : ";
	cin>>curr->city;
	transform(curr->city.begin(), curr->city.end(), curr->city.begin(), ::toupper);

	curr->down=NULL;
	curr->next=NULL;
	if(root==NULL)
	{
		root=curr;
		prev=curr;
	}
	else
	{
			prev->down=curr;
			prev=curr;
	}
}

void flight :: insert()
{
	curr=new flight_node;
	int flag=0;
	flight_node *temp=root,*temp1;
	cout<<"\nENTER SOURCE CITY : ";
	cin>>source_city;
	transform(source_city.begin(), source_city.end(), source_city.begin(), ::toupper);

	cout<<"ENTER DESTINATION CITY : ";
	cin>>des_city;
	transform(des_city.begin(), des_city.end(), des_city.begin(), ::toupper);

	while(temp!=NULL)
	{
		if(temp->city == source_city)
		{
			temp1=temp;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}
			curr->city=des_city;
			cout<<"ENTER TIME NEEDED : ";
			cin>>curr->time;
			curr->next=NULL;
			curr->down=NULL;
			temp1->next=curr;
			cout<<"\n\t!!! SUCCESFULLY ADDED !!!\n";
			flag=1;
		}
		temp=temp->down;
	}
	if(flag==0)
	{
		cout<<"\n\t!!! CITY NAME DOESN'T FOUND !!!";
	}
}

void flight :: display()
{
	flight_node *temp=root,*temp1;
	int flag=0;
	while(temp!=NULL)
	{
		cout<<"\nCITY : ";
		cout<<temp->city;
		temp1=temp;
		temp1=temp1->next;
		cout<<"\nCONNECTED CITIES : ";
			while(temp1!=NULL)
			{
				cout<<" '"<<temp1->city<<"'";
				temp1=temp1->next;
				flag=1;
			}

			if(flag==0)
				cout<<" - ";
		temp=temp->down;
	}
}

void flight :: pflight()
{
	flight_node *temp=root,*temp1,*temp2=root;
	int flag=0,cflag=0;
	cout<<"\nENTER SOURCE CITY : ";
	cin>>source_city;
	transform(source_city.begin(), source_city.end(), source_city.begin(), ::toupper);

	cout<<"ENTER DESTINATION CITY : ";
	cin>>des_city;
	transform(des_city.begin(), des_city.end(), des_city.begin(), ::toupper);

	while(temp!=NULL)
	{
		if(temp->city==source_city)
		{
			temp1=temp;
			temp1=temp1->next;
			while(temp1!=NULL)
			{
				if(temp1->city==des_city)
				{
					cout<<"\nTHERE IS A ROUTE : '"<<temp->city<<"' ✈ '"<<temp1->city<<"'";
					cout<<"\nTIME NEEDED IS : "<<temp1->time;
					flag=1;
				}
				else
				{
					while(temp2!=NULL)
					{
						if(temp2->city==temp1->city)
							break;

						temp2=temp2->down;
					}
					while(temp2!=NULL)
					{
						if(temp2->city==des_city)
						{
							cout<<"\nTHERE IS A ROUTE : '"<<temp->city<<"' ✈ '"<<temp1->city<<"' ✈ '"<<temp2->city<<"'";
							cout<<"\nTIME NEEDED IS : "<<temp1->time + temp2->time;
							flag=1;
						}
						temp2=temp2->next;
					}
				}
				temp1=temp1->next;
			}
			cflag=1;
		}
		temp=temp->down;
	}
	if(flag==0 && cflag==1)
	{
		cout<<"\n\t!!! NO FLIGHT FOUND !!!";
	}
	if(cflag==0)
		cout<<"\n\t!!! CITY NAME DOESN'T FOUND !!!";
}

void flight :: connected_city()
{
	flight_node *temp=root;
	int flag=0,cflag=0;

	cout<<"\nENTER NAME OF THE CITY : ";
	cin>>source_city;
	transform(source_city.begin(), source_city.end(), source_city.begin(), ::toupper);

	cout<<"\nCONNCTED CITIES : ";
	while(temp!=NULL)
	{
		if(temp->city==source_city)
		{
			while(temp->next!=NULL)
			{
				cout<<"\n"<<temp->next->city;
				flag=1;
				temp=temp->next;
			}
			cflag=1;
		}
		temp=temp->down;
	}
	if(flag==0 && cflag==1)
		cout<<"\n\t!!! NO CITIES CONNECTED !!!";
	if(cflag==0)
		cout<<"\n\t!!! CITY NAME DOESN'T FOUND !!!";
}

int main()
{
	flight f;
	int ch;
	char choice;
	cout<<"\nENTER NUMBER OF CITIES : ";
	cin>>ch;
	for(int i=0;i<ch;i++)
	{
		f.city();
	}
	cout<<"\nENTER ROUTES BETWEEN CITIES : ";
	do
	{
		f.insert();
		cout<<"\nDO U WANT TO ENTER ANOTHER (y/n) : ";
		cin>>choice;
	}while(choice=='Y' || choice=='y');

		cout<<"\n  PLEASE WAIT ... ";
		cout<<"\n";
	do
	{
		sleep(3);
		system("clear");
		cout<<"\n\t\tWELCOME TO FLIGHT SERVICES";
		cout<<"\n\t\t ----> MENU <----";
		cout<<"\n\t\t 1. DISPLAY ROUTES";
		cout<<"\n\t\t 2. CHECK FLIGHT";
		cout<<"\n\t\t 3. CONNECTED CITIES";
		cout<<"\n\t\t 4. EXIT";
		cout<<"\n\t\t ENTER CHOICE : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
					f.display();
					break;

			case 2:
					f.pflight();
					break;

			case 3:
					f.connected_city();
					break;

			case 4:
					cout<<"\n\t!!! THANK YOU !!!";
					break;

			default:
					cout<<"\n\t!!! INVALID CHOICE !!!";
		}

		if(ch!=4)
			cout<<"\n\n  PLEASE WAIT ... ";

		cout<<"\n";
	}while(ch!=4);

}

/*
	OUTPUT

ENTER NUMBER OF CITIES : 4
ENTER NAME OF THE CITY : mumbai
ENTER NAME OF THE CITY : pune
ENTER NAME OF THE CITY : nashik
ENTER NAME OF THE CITY : nagpur

ENTER ROUTES BETWEEN CITIES : 
ENTER SOURCE CITY : nashikk
ENTER DESTINATION CITY : pune

	!!! CITY NAME DOESN'T FOUND !!!
DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : nahik
ENTER DESTINATION CITY : pune

	!!! CITY NAME DOESN'T FOUND !!!
DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : nashik
ENTER DESTINATION CITY : pune
ENTER TIME NEEDED : 4

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : nashik
ENTER DESTINATION CITY : mumbai
ENTER TIME NEEDED : 3

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : pune
ENTER DESTINATION CITY : nashik
ENTER TIME NEEDED : 4

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : pune
ENTER DESTINATION CITY : mumbai
ENTER TIME NEEDED : 8

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : mumbai
ENTER DESTINATION CITY : nashik 
ENTER TIME NEEDED : 3

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : mumbai
ENTER DESTINATION CITY : pune
ENTER TIME NEEDED : 8

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : mumbai
ENTER DESTINATION CITY : nagpur
ENTER TIME NEEDED : 12

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : y

ENTER SOURCE CITY : nagpur
ENTER DESTINATION CITY : mumbai
ENTER TIME NEEDED : 12

	!!! SUCCESFULLY ADDED !!!

DO U WANT TO ENTER ANOTHER (y/n) : n


		WELCOME TO FLIGHT SERVICES
		 ----> MENU <----
		 1. DISPLAY ROUTES
		 2. CHECK FLIGHT
		 3. CONNECTED CITIES
		 4. EXIT
		 ENTER CHOICE : 1

CITY : MUMBAI
CONNECTED CITIES :  'NASHIK' 'PUNE' 'NAGPUR'
CITY : PUNE
CONNECTED CITIES :  'NASHIK' 'MUMBAI'
CITY : NASHIK
CONNECTED CITIES :  'PUNE' 'MUMBAI'
CITY : NAGPUR
CONNECTED CITIES :  'MUMBAI'

  PLEASE WAIT ... 

		WELCOME TO FLIGHT SERVICES
		 ----> MENU <----
		 1. DISPLAY ROUTES
		 2. CHECK FLIGHT
		 3. CONNECTED CITIES
		 4. EXIT
		 ENTER CHOICE : 2

ENTER SOURCE CITY : nagpur
ENTER DESTINATION CITY : nashik

THERE IS A ROUTE : 'NAGPUR' ✈ 'MUMBAI' ✈ 'NASHIK'
TIME NEEDED IS : 15

  PLEASE WAIT ... 

		WELCOME TO FLIGHT SERVICES
		 ----> MENU <----
		 1. DISPLAY ROUTES
		 2. CHECK FLIGHT
		 3. CONNECTED CITIES
		 4. EXIT
		 ENTER CHOICE : 2

ENTER SOURCE CITY : nashik
ENTER DESTINATION CITY : mumbai

THERE IS A ROUTE : 'NASHIK' ✈ 'PUNE' ✈ 'MUMBAI'
TIME NEEDED IS : 12
THERE IS A ROUTE : 'NASHIK' ✈ 'MUMBAI'
TIME NEEDED IS : 3

  PLEASE WAIT ... 

		WELCOME TO FLIGHT SERVICES
		 ----> MENU <----
		 1. DISPLAY ROUTES
		 2. CHECK FLIGHT
		 3. CONNECTED CITIES
		 4. EXIT
		 ENTER CHOICE : 3

ENTER NAME OF THE CITY : nashik

CONNCTED CITIES : 
PUNE
MUMBAI

  PLEASE WAIT ... 

		WELCOME TO FLIGHT SERVICES
		 ----> MENU <----
		 1. DISPLAY ROUTES
		 2. CHECK FLIGHT
		 3. CONNECTED CITIES
		 4. EXIT
		 ENTER CHOICE : 4

	!!! THANK YOU !!!
*/
