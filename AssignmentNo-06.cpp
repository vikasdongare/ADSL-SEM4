/*
                                    ASSIGNMENT NO - 06 (Using Adjacency matrix)

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
#define MAX 10
using namespace std;

class flight
{
	public:
			string city[MAX],source_city,des_city;
			int time[MAX][MAX],city_no,i,j;

			flight()
			{
				city_no=MAX;
				for(i=0;i<city_no;i++)
				{
					for(j=0;j<city_no;j++)
					{
						time[i][j]=0;
					}
				}
			}
			void cities();
			void route();
			void display();
			void pflight();
			void connected_cities();
};

void flight :: cities()
{
	cout<<"\nENTER NUMBER OF CITIES U WANT TO ENTER : ";
	cin>>city_no;

	for(i=0; i<city_no; i++)
	{
		string su;
		cout<<"ENTER CITY NAME : ";
		cin>>su;
		transform(su.begin(), su.end(), su.begin(), ::toupper);
		city[i]=su;
	}
}


void flight :: route()
{
	char choice;

	for(i=0;i<city_no;i++)
	{
		for(j=0;j<city_no;j++)
		{

			if(i!=j)
			{
				cout<<"\nWHETHER THERE IS ROUTE BETWEEN '"<<city[i]<<"' AND '"<<city[j]<<"' (y/n) : ";
				cin>>choice;
				if(choice == 'Y' || choice == 'y')
				{
					cout<<"ENTER TIME NEEDED TO REACH : ";
					cin>>time[i][j];
				}
			}
		}
	}
}

void flight :: display()
{
	for(i=0;i<city_no;i++)
		{
			for(j=0;j<city_no;j++)
				{
					if(time[i][j]!=0 && i!=j)
					{
						cout<<"\nTHERE IS ROUTE BETWEEN : '"<<city[i]<<"' AND '"<<city[j]<<"'";
						cout<<"\nTIME NEEDED IS : ";
						cout<<time[i][j];
					}
				}
		}

}

void flight :: pflight()
{
	int flag=0;
	cout<<"\nENTER SOURCE CITY : ";
	cin>>source_city;
	transform(source_city.begin(), source_city.end(), source_city.begin(), ::toupper);

	cout<<"ENTER DESTINATION CITY : ";
	cin>>des_city;
	transform(des_city.begin(), des_city.end(), des_city.begin(), ::toupper);

	for(i=0;i<city_no;i++)
	{
		if(city[i] == source_city)
		{
			for(j=0;j<city_no;j++)
			{
				if(city[j] == des_city && time[i][j]!=0)
				{
					cout<<"\nTHERE IS ROUTE BETWEEN : '"<<city[i]<<"' -> '"<<city[j]<<"'";
					cout<<"\nTIME NEEDED IS : ";
					cout<<time[i][j];
					flag=1;
				}
				int k=0;
				while(k<city_no)
				{
					if(city[k] == des_city && time[i][j]!=0 && time[j][k]!=0)
					{
						cout<<"\nTHERE IS ROUTE BETWEEN : '"<<city[i]<<"' -> '"<<city[j]<<"' -> '"<<city[k]<<"'";
						cout<<"\nTIME NEEDED IS : ";
						cout<<time[i][j]+time[j][k];
						flag=1;
					}
					k++;
				}
			}
		}
	}
	if(flag==0)
			cout<<"\n\t!!! THERE IS NO DIRECT PATH BETWEEN CITIES ";
}

void flight :: connected_cities()
{
	int flag=0;
	cout<<"\nENTER CITY NAME : ";
	cin>>source_city;
	transform(source_city.begin(), source_city.end(), source_city.begin(), ::toupper);

	for(int k=0;k<city_no;k++)
	{
		if(city[k] == source_city)
			i=k;
	}

	j=0;

	while(j<city_no && j!=i)
	{
		if(time[i][j]!=0)
		{
			cout<<"\nTHERE IS ROUTE BETWEEN : '"<<city[i]<<"' AND '"<<city[j]<<"'";
			cout<<"\nTIME NEEDED IS : ";
			cout<<time[i][j];
			flag=1;
			j++;
		}
		else
		{
			j++;
			continue;
		}
	}

	if(flag==0)
		cout<<"\n\t!!! NONE OF CITIES ARE CONNECTED TO THIS CITY !!!";
}

int main()
{
	flight f;
	int choice;
	f.cities();
	f.route();
	do
	{
		cout<<"\n========================================";
		cout<<"\n\t----> MENU <----";
		cout<<"\n\t1. Display routes ";
		cout<<"\n\t2. Check flight";
		cout<<"\n\t3. Connected Cities";
		cout<<"\n\t4. Exit";
		cout<<"\n\tENTER YOUR CHOICE : ";
		cin>>choice;
		cout<<"\n========================================";

		switch(choice)
		{
			case 1:
					f.display();
					break;
			case 2:
					f.pflight();
					break;

			case 3:
					f.connected_cities();
					break;

			case 4:
					break;

			default:
					cout<<"\n\t!!! INVALID CHOICE !!!";

		}

	}while(choice!=4);
}

/*
	OUTPUT
	
ENTER NUMBER OF CITIES U WANT TO ENTER : 3
ENTER CITY NAME : pune
ENTER CITY NAME : nashik
ENTER CITY NAME : mumbai

WHETHER THERE IS ROUTE BETWEEN 'PUNE' AND 'NASHIK' (y/n) : y
ENTER TIME NEEDED TO REACH : 4

WHETHER THERE IS ROUTE BETWEEN 'PUNE' AND 'MUMBAI' (y/n) : y
ENTER TIME NEEDED TO REACH : 8

WHETHER THERE IS ROUTE BETWEEN 'NASHIK' AND 'PUNE' (y/n) : y
ENTER TIME NEEDED TO REACH : 4

WHETHER THERE IS ROUTE BETWEEN 'NASHIK' AND 'MUMBAI' (y/n) : y
ENTER TIME NEEDED TO REACH : 3

WHETHER THERE IS ROUTE BETWEEN 'MUMBAI' AND 'PUNE' (y/n) : y
ENTER TIME NEEDED TO REACH : 8

WHETHER THERE IS ROUTE BETWEEN 'MUMBAI' AND 'NASHIK' (y/n) : y
ENTER TIME NEEDED TO REACH : 3

========================================
	----> MENU <----
	1. Display routes 
	2. Check flight
	3. Connected Cities
	4. Exit
	ENTER YOUR CHOICE : 1

========================================
THERE IS ROUTE BETWEEN : 'PUNE' AND 'NASHIK'
TIME NEEDED IS : 4
THERE IS ROUTE BETWEEN : 'PUNE' AND 'MUMBAI'
TIME NEEDED IS : 8
THERE IS ROUTE BETWEEN : 'NASHIK' AND 'PUNE'
TIME NEEDED IS : 4
THERE IS ROUTE BETWEEN : 'NASHIK' AND 'MUMBAI'
TIME NEEDED IS : 3
THERE IS ROUTE BETWEEN : 'MUMBAI' AND 'PUNE'
TIME NEEDED IS : 8
THERE IS ROUTE BETWEEN : 'MUMBAI' AND 'NASHIK'
TIME NEEDED IS : 3
========================================
	----> MENU <----
	1. Display routes 
	2. Check flight
	3. Connected Cities
	4. Exit
	ENTER YOUR CHOICE : 2

========================================
ENTER SOURCE CITY : nashik
ENTER DESTINATION CITY : pune

THERE IS ROUTE BETWEEN : 'NASHIK' -> 'PUNE'
TIME NEEDED IS : 4
THERE IS ROUTE BETWEEN : 'NASHIK' -> 'MUMBAI' -> 'PUNE'
TIME NEEDED IS : 11
========================================
	----> MENU <----
	1. Display routes 
	2. Check flight
	3. Connected Cities
	4. Exit
	ENTER YOUR CHOICE : 3

========================================
ENTER CITY NAME : nashik

THERE IS ROUTE BETWEEN : 'NASHIK' AND 'PUNE'
TIME NEEDED IS : 4
THERE IS ROUTE BETWEEN : 'NASHIK' AND 'MUMBAI'
TIME NEEDED IS : 3
========================================
	----> MENU <----
	1. Display routes 
	2. Check flight
	3. Connected Cities
	4. Exit
	ENTER YOUR CHOICE : 5

========================================
	!!! INVALID CHOICE !!!
========================================
	----> MENU <----
	1. Display routes 
	2. Check flight
	3. Connected Cities
	4. Exit
	ENTER YOUR CHOICE : 4

========================================
*/
