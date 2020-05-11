/*
                                    ASSIGNMENT NO - 10
Assignment Statement:- Read a marks obtained by students of second year in an online examination of a particular subject.Find minimu and
                       maximum marks obtained in that subject.Use heap data structure.Analyze algorithm.
Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B
*/
#include<iostream>
#define MAX 10
using namespace std;

class heap_sort
{
    int marks[MAX],i,no_of_stud;

    public:
            heap_sort()
            {
                for(int i=0;i<MAX;i++)
                    marks[i] = 0;
            }

            void get();
            void print();
            void heapsort(int choice);
            void maxheap(int n, int i);
            void minheap(int n, int i);
            int getmaxmark();
            int getminmark();
};

//get function to get details
void heap_sort :: get()
{
    label:
    cout<<"\n ENTER NUMBER OF STUDENTS : ";
    cin>>no_of_stud;
    if(no_of_stud > 0)
    {
        cout<<"\nENTER MARKS OBTAINED : \n";
        for(int i=0; i<no_of_stud; i++)
        {
            cout<<i+1<<"]\t";
            cin>>marks[i];
        }
    }
    else
    {
        cout<<"\n\t!!! ENTER APPROPRIATE STUDENTS !!!";
        goto label;
    }
}

//maxheap function for converting heap into maxheap. The paramenter i is node position and n is the total number of students
void heap_sort :: maxheap(int n, int i)
{
    int largest = i;
    int l = (2*i)+1;  //calculating left child position
    int r = (2*i)+2;  //calculating right child position

    if(l<n && marks[l] > marks[largest])
        largest = l;

    if(r<n && marks[r] > marks[largest])
        largest = r;

    if( largest != i)
    {
        swap(marks[i], marks[largest]);
        maxheap(n, largest);
    }
}


//minheap function for converting heap into minheap. The paramenter i is node position and n is the total number of students
void heap_sort :: minheap(int n, int i)
{
    int smallest = i;
    int l = (2*i)+1;   //calculating left child position
    int r = (2*i)+2;   //calculating right child position

    if(l<n && marks[l] < marks[smallest])
        smallest = l;

    if(r<n && marks[r] < marks[smallest])
        smallest = r;

    if( smallest != i)
    {
        swap(marks[i], marks[smallest]);
        minheap(n, smallest);
    }
}


void heap_sort :: heapsort(int choice)
{
    for(i = (no_of_stud/2)-1; i >= 0; i--)   //Loop to start from second last level of the heap
    {
        if(choice == 1)
            maxheap(no_of_stud, i);
        else
            minheap(no_of_stud, i);
    }

    for(i = no_of_stud-1; i > 0; i--)     //Loop to get marks from heap structure
    {
        swap(marks[0], marks[i]);
        if(choice == 1)
            maxheap(i, 0);
        else
            minheap(i, 0);
    }
}

void heap_sort :: print()
{
    cout<<"\nDISPLAYING MARKS : \n";
    for(int i=0; i<no_of_stud; i++)
    {
        cout<<i+1<<"]\t"<<marks[i]<<"\n";
    }
}

int heap_sort :: getmaxmark()
{
    heapsort(1);
    cout<<"\n\t\tTHE MAXIMUM MARK : "<<marks[no_of_stud-1];
}

int heap_sort :: getminmark()
{
    heapsort(2);
    cout<<"\n\t\tTHE MINIMUM MARK : "<<marks[no_of_stud-1];
}

int main()
{
    int choice;
    heap_sort h;
    h.get();
   //h.print();

    do
    {
        cout<<"\n\t\t---> MENU <---";
        cout<<"\n\t1] Get Maximum Mark";
        cout<<"\n\t2] Get Minimum Mark";
        cout<<"\n\t3] Get Maximum and Minimum Mark";
        cout<<"\n\t4] Exit";
        cout<<"\nENTER YOUR CHOICE : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                h.getmaxmark();
                break;
            case 2:
                h.getminmark();
                break;
            case 3:
                h.getmaxmark();
                h.getminmark();
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t !!! INCORRECT CHOICE !!!";
        }
    }while(choice!=4);
    return 0;
}

/*
	OUTPUT


 ENTER NUMBER OF STUDENTS : -1

	!!! ENTER APPROPRIATE STUDENTS !!!
 ENTER NUMBER OF STUDENTS : 0

	!!! ENTER APPROPRIATE STUDENTS !!!
 ENTER NUMBER OF STUDENTS : 5

ENTER MARKS OBTAINED :
1]	12
2]	56
3]	9
4]	23
5]	78

		---> MENU <---
	1] Get Maximum Mark
	2] Get Minimum Mark
	3] Get Maximum and Minimum Mark
	4] Exit
ENTER YOUR CHOICE : 1

		THE MAXIMUM MARK : 78
		---> MENU <---
	1] Get Maximum Mark
	2] Get Minimum Mark
	3] Get Maximum and Minimum Mark
	4] Exit
ENTER YOUR CHOICE : 2

		THE MINIMUM MARK : 9
		---> MENU <---
	1] Get Maximum Mark
	2] Get Minimum Mark
	3] Get Maximum and Minimum Mark
	4] Exit
ENTER YOUR CHOICE : 3

		THE MAXIMUM MARK : 78
		THE MINIMUM MARK : 9
		---> MENU <---
	1] Get Maximum Mark
	2] Get Minimum Mark
	3] Get Maximum and Minimum Mark
	4] Exit
ENTER YOUR CHOICE : 5

		 !!! INCORRECT CHOICE !!!
		---> MENU <---
	1] Get Maximum Mark
	2] Get Minimum Mark
	3] Get Maximum and Minimum Mark
	4] Exit
ENTER YOUR CHOICE : 4

*/
