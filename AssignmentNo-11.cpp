/*
                                    ASSIGNMENT NO - 11
Assignment Statement:- Department maintains the student information.The file contaions name,roll number,division,address.Allow user to add,
                       delete information of student.Display informationof particular student.If record o particular student does not exits
                       an approprite message is displayed. If it is,then the system display student details.Use sequentialile to maintain
                       data.

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;

class information
{
public:
	int rollNo;
	char division[2];
	char CLASS[5];
	char name[30];
	char address[30];
	information()
	{
		rollNo=0;
		strcpy(division," ");
		strcpy(CLASS," ");
		strcpy(name," ");
		strcpy(address," ");
	}
	void getData();
	void display();
};
class studentInfo
{
public:
	fstream file;
	information temp1;

	void putData();
	void searchData();
	void deleteData();
	void modifyData();
	void displayData();
};

void information::getData()
{
	cout<<"\nEnter Roll Number: ";
	cin>>rollNo;
	cout<<"Enter Name       : ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"Enter class      : ";
	cin>>CLASS;
	cout<<"Enter Division   : ";
	cin>>division;
	cout<<"Enter Address    : ";
	cin.ignore();
	cin.getline(address,30);
}
void information::display()
{
	cout<<setw(10)<<rollNo<<setw(20)<<name<<setw(12)<<CLASS<<setw(8)<<division<<setw(20)<<address<<endl;
}
void display1()
{
	cout<<setw(12)<<"Roll No"<<setw(12)<<"Name"<<setw(20)<<"Class"<<setw(12)<<"Division"<<setw(12)<<"Address"<<setw(12)<<endl;
}

void studentInfo::putData()
{
	int wloc,no;
	file.open("Student_Information.txt",ios::out|ios::in|ios::app);
	cout<<"\nEnter Number of Data to be added: ";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		temp1.getData();
		file.write((char *)&temp1,sizeof(temp1));
	}
	file.close();

}
void studentInfo::searchData()
{
	int searchNo,sloc=0;
	char div[2],Class[5];
	file.open("Student_Information.txt",ios::out|ios::in);
	cout<<"\nEnter Class: ";
	cin>>Class;
    cout<<"Enter Division: ";
    cin>>div;
    cout<<"Enter Roll Number: ";
    cin>>searchNo;
    display1();
    while(file.read(reinterpret_cast<char*>(&temp1),sizeof(temp1))){
    	if(searchNo==temp1.rollNo && strcasecmp(Class,temp1.CLASS)==0 && strcasecmp(div,temp1.division)==0){
    		temp1.display();
    		sloc=1;
    	}
    }
    if(sloc==0)
		cout<<"\n\t!!! Data NOT Found !!!"<<endl;
    file.close();
}
void studentInfo::deleteData()
{
	int deleteNo,dloc=0;
	char div[2],Class[5];
	fstream file1;
	cout<<"\nEnter Class: ";
	cin>>Class;
    cout<<"Enter Division: ";
    cin>>div;
    cout<<"Enter Roll Number: ";
    cin>>deleteNo;
    file.open("Student_Information.txt",ios::in);
	file1.open("Student_Information1.txt",ios::out);

   	while(file.read((char*)&temp1,sizeof(temp1))){
   		if(deleteNo==temp1.rollNo && strcasecmp(Class,temp1.CLASS)==0 && strcasecmp(div,temp1.division)==0){
    		display1();
   			temp1.display();
   			dloc=1;
   		}
   		else
   			file1.write((char*)&temp1,sizeof(temp1));
   	}
    file.close();
    file1.close();
   remove("Student_Information.txt");
   rename("Student_Information1.txt","Student_Information.txt");
    if(dloc==1)
	    cout<<"\n\t!!! Record deleted successfully !!!"<<endl;
	else
		cout<<"\n\t!!! Data NOT Found !!!"<<endl;
}
void studentInfo::modifyData()
{
	int	modifyNo,mloc=0;
	char div[2],Class[5];
	file.open("Student_Information.txt",ios::out|ios::in);
	cout<<"\nEnter Class: ";
	cin>>Class;
    cout<<"Enter Division: ";
    cin>>div;
    cout<<"Enter Roll Number: ";
    cin>>modifyNo;
    while(file.read(reinterpret_cast<char*>(&temp1),sizeof(temp1))){
    	if(modifyNo==temp1.rollNo && strcasecmp(Class,temp1.CLASS)==0 && strcasecmp(div,temp1.division)==0){
    		cout<<"\nEnter New Data :";
    		temp1.getData();
    		mloc = -1* sizeof(temp1);
    		file.seekp(mloc,ios::cur);
    		file.write((char*)&temp1,sizeof(temp1));
    		mloc=1;
    		break;
    	}
    }
    file.close();
    if(mloc==1)
    	cout<<"\n\t!!! Record updated successfully !!!"<<endl;
    else
    	cout<<"\n\t!!! Record NOT Found !!!"<<endl;
}
void studentInfo::displayData()
{
	display1();
	file.open("Student_Information.txt",ios::in);
	while(file.read(reinterpret_cast<char*>(&temp1),sizeof(temp1)))
	{
		temp1.display();
	}
	file.close();
}
int main()
{
	int ch;
	char ch1;
	studentInfo stIn;
	do{
		cout<<"\n\t= = = > MENU < = = = \n";
		cout<<"\n\t 1. Enter Data In the File ";
		cout<<"\n\t 2. Display All Data in File ";
		cout<<"\n\t 3. Search Data in the File ";
		cout<<"\n\t 4. Delete Data in the File";
		cout<<"\n\t 5. Modify Data in the File";
		cout<<"\n\t 6. EXIT";
		cout<<"\n====================================\n";
		cout<<"Enter Choice: ";
		cin>>ch;
		switch(ch)
		{

			case 1:
				stIn.putData();
				break;

			case 2:
				stIn.displayData();
				break;

            case 3:
				stIn.searchData();
                break;
            case 4:
            	stIn.deleteData();
           		break;

            case 5:
            	stIn.modifyData();
                break;
            case 6:
              	break;
            default:
                cout<<"\n\t\t !!! INVALID CHOICE !!!";
		}
	}while(ch != 6);
	return 0;
}

/*
    OUPUT
        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 2
     Roll No        Name               Class    Division     Address
         4       mayur badwaik          se       b   panchavati nashik
        17          akash giri          se       b    amrutdham nashik

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 1

Enter Number of Data to be added: 1

Enter Roll Number: 16
Enter Name       : dhiraj ganeshkar
Enter class      : se
Enter Division   : b
Enter Address    : amrutdham nashik

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 2
     Roll No        Name               Class    Division     Address
         4       mayur badwaik          se       b   panchavati nashik
        17          akash giri          se       b    amrutdham nashik
        16    dhiraj ganeshkar          se       b    amrutdham nashik

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 3

Enter Class: se
Enter Division: b
Enter Roll Number: 17
     Roll No        Name               Class    Division     Address
        17          akash giri          se       b    amrutdham nashik

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 4

Enter Class: se
Enter Division: b
Enter Roll Number: 17
     Roll No        Name               Class    Division     Address
        17          akash giri          se       b    amrutdham nashik

        !!! Record deleted successfully !!!

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 2
     Roll No        Name               Class    Division     Address
         4       mayur badwaik          se       b   panchavati nashik
        16    dhiraj ganeshkar          se       b    amrutdham nashik

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 5

Enter Class: se
Enter Division: b
Enter Roll Number: 16

Enter New Data :
Enter Roll Number: 15
Enter Name       : vikas dongare
Enter class      : se
Enter Division   : b
Enter Address    : panchavati nashik

        !!! Record updated successfully !!!

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 2
     Roll No        Name               Class    Division     Address
         4       mayur badwaik          se       b   panchavati nashik
        15       vikas dongare          se       b   panchavati nashik

        = = = > MENU < = = =

         1. Enter Data In the File
         2. Display All Data in File
         3. Search Data in the File
         4. Delete Data in the File
         5. Modify Data in the File
         6. EXIT
====================================
Enter Choice: 6
*/
