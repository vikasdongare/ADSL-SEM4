/*
										ASSIGNMENT NO - 01

Assignment Statement:- Implement the Heap/Shell sort algorithm implemented in JAVA demonstrating Heap/Shell data structure with 
					   modularity of programming language

Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE 
DIV    :- B
*/

import java.util.Scanner;
class AssignmentNo_01 //CALSS START
{
	public static int a[]=new int[50];
	public static int b[]=new int[50];
	public static int c[]=new int[50];
	
	public static int n,i;//VARIABLE DECLARATION
	public static void read()//START OF READ FUNCTION
	{
		Scanner s=new Scanner(System.in);
		System.out.println("\nEnter the Size of Array:");
		n=s.nextInt();
		System.out.println("\nEnter Elements of Array:");
		for(i=0;i<n;i++)
		{
			b[i]=s.nextInt();
		}
		for(i=0;i<n;i++)
	 	{
	 		a[i]=b[i];	
	 		c[i]=b[i];
		}	
	}//end of read

	public static void initilize()//START OF FUNCTION INITILIZE
	 {
	 	n=10;
	 	int m[]=new int[] {129,30,80,60,10,5,122,92,69,55};
	 	for(i=0;i<n;i++)
	 	{
	 		a[i]=m[i];	
	 		c[i]=m[i];
		}	 
	 }//END OF FUNCTION INITILIZE
	 public static void display()//START OF DISPLAY FUNCTION
	 {
	 	System.out.println("\nElements of Array are :");
		
		for(i=0;i<n;i++)
		{
			System.out.print("  "+a[i]);
		}
		System.out.println();
	 }//end of display
	 public static void passd()
	 {
	 	System.out.print("PASS : ");
		for(i=0;i<n;i++)
		{
			System.out.print("  "+a[i]);
		}
		System.out.println();
	 }//end of passd
	public static void heapsort()//START OF HEAP SORT FUNCTION
	 {
	 	for(i=(n-1)/2;i>=0;i--)
	 	{
	 		reheapdown(i,n);//CALL FOR REHEAPDOWN
	 	}
	 	int n1=n;
	 	n1--;
	 	
	 	while(n1>1)
	 	{
	 		int t=a[n1];
	 		a[n1]=a[0];
	 		a[0]=t;
	 		reheapdown(0,n1);//CALL FOR REHEAPDOWN
	 		n1--;
	 		passd();
	 	}
	 	
	 }//end of heapsort
	 
	public static void reheapdown(int m,int n)////START OF REHEAPDOWN
	 {
	 	int l;
	 	int r;
	 	
	 	while((2*m+1)<n)
	 	{
	 		l=2*m+1;
	 		r=2*m+2;
	 			
	 		if(a[l]>a[r]&&l<n)
	 		{
	 			
	 			if(a[m]<=a[l])
	 			{
	 				int t=a[m];
	 				a[m]=a[l];
	 				a[l]=t;
	 			}
	 			else 
	 				break;
	 		}
	 		else if (a[l]<=a[r]&&r<n)
	 		{
	 			l=r;
	 			if(a[m]<=a[l])
	 			{
	 				int t=a[m];
	 				a[m]=a[l];
	 				a[l]=t;
	 			}
	 			else 
	 				break;
	 		}
	 		else 
	 			break;		
	 		m=l;
	 	}
	 } //end of reheapdown
	public static void shellshort()//START OF SHELL SORT
	 {
		int swapped=0;
		int gap=n/2;
		do
		{	
			do
			{
				swapped=0;
				for(i=0;i<n-gap;i++)
				{
					if(c[i]>c[i+gap])
					{
						int temp=c[i];
						c[i]=c[i+gap];
						c[i+gap]=temp;
						swapped=1;
					}
				}
			}while(swapped==1);
			passd();
		}while((gap=(gap/2))>=1);		
	 }//END OF SHELL SORT
	public static void main(String args[])//START OF MAIN FUNCTION
	{
		int ch;
		Scanner c=new Scanner(System.in);
		do{
			System.out.println("---------------");
			System.out.println("1.Read Elements ");
			System.out.println("2.Initilize Array Elements");
			System.out.println("3.Display Elements ");
			System.out.println("4.Heap Sort ");
			System.out.println("5.Shell Sort");
			System.out.println("6.Exit      ");
			System.out.println("---------------");
			System.out.print("choice:");
			ch=c.nextInt();

			switch(ch)
			{
				case 1:
					read();
					break;
				case 2:
					initilize();
					break;
				case 3:
					display();
					break;
				case 4:
					System.out.println("Heap Sort :");
					heapsort();
					break;
				case 5:
					System.out.println("Shell Sort :");
					shellshort();
					break;
				case 6:
					System.out.println("\nEXIT ");
					break;
			}
		}while(ch!=6);
	}//END OF MAIN FUNCTION 
};//END OF CLASS;

//  OUTPUT
//
/*
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:1

Enter the Size of Array:
10

Enter Elements of Array:
20
30
54
78
96
14
25
36
14
22
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:3

Elements of Array are :
  20  30  54  78  96  14  25  36  14  22
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:4
Heap Sort :
PASS :   78  36  54  22  30  14  25  20  14  96
PASS :   54  36  25  22  30  14  14  20  78  96
PASS :   36  30  25  22  20  14  14  54  78  96
PASS :   30  22  25  14  20  14  36  54  78  96
PASS :   25  22  14  14  20  30  36  54  78  96
PASS :   22  20  14  14  25  30  36  54  78  96
PASS :   20  14  14  22  25  30  36  54  78  96
PASS :   14  14  20  22  25  30  36  54  78  96
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:5
Shell Sort :
PASS :   14  14  20  22  25  30  36  54  78  96
PASS :   14  14  20  22  25  30  36  54  78  96
PASS :   14  14  20  22  25  30  36  54  78  96
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:2
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:3

Elements of Array are :
  129  30  80  60  10  5  122  92  69  55
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:4
Heap Sort :
PASS :   122  92  80  69  55  5  10  60  30  129
PASS :   92  69  80  30  55  5  10  60  122  129
PASS :   80  69  60  30  55  5  10  92  122  129
PASS :   69  55  60  30  10  5  80  92  122  129
PASS :   60  55  5  30  10  69  80  92  122  129
PASS :   55  10  5  30  60  69  80  92  122  129
PASS :   30  10  5  55  60  69  80  92  122  129
PASS :   5  10  30  55  60  69  80  92  122  129
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:5
Shell Sort :
PASS :   5  10  30  55  60  69  80  92  122  129
PASS :   5  10  30  55  60  69  80  92  122  129
PASS :   5  10  30  55  60  69  80  92  122  129
---------------
1.Read Elements
2.Initilize Array Elements
3.Display Elements
4.Heap Sort
5.Shell Sort
6.Exit
---------------
choice:6

EXIT
*/
