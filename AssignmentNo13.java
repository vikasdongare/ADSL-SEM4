/* 	
										ASSIGNMENT NO:13
	
Assignment STATEMENT:  CREATE A CLASS EMPLOYEE
		               DATA MEMBERS
		               NAME : STRING
		               MOBILE : STRING
		               BIRTH_DATE : DATE     (AGE : INT )
		               SALARY : FLOAT
		               CREATE EMPLOYEE RECORDS OF MAXIMUM 5 EMPLOYEES AND VALIDATE INPUT THROUGH EXCEPTIONS
		               1. AGE < 18 NOT ALLOWED   2. MOBILE NUMBER = 10 DIGITS ONLY 3. SALARY SHOULD NOT BE <=0
		               CHECK ARRAY LIMIT BOUND ERROR FOR EMPLOYEE DATA MORE THAN 5 RECORDS

							
Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B

*/

import java.util.*;

class salary_exception extends Exception			//extending user defined SalaryException
{
    salary_exception(String msg)
	{
		super(msg);
	}
};
class mobile_limit_exception extends Exception			//extending user defined MobileLimitException
{
	mobile_limit_exception(String msg)
	{
		super(msg);
	}
};
class age_limit_exception extends Exception				//extending user defined AgeLimitException
{
	age_limit_exception(String msg)
	{
		super(msg);
	}
};
class array_limit_out_of_bound_exception extends Exception	    //extending user defined ArrayIndexoutofBoundException
{
	array_limit_out_of_bound_exception(String msg)
	{
		super(msg);
	}
};

class Employee
{
       String name;
       String mobile_no;
       String birth_date;
       float salary;
       int age;

	public void accept()
	{
		Scanner sc=new Scanner(System.in);
		try
		{
			System.out.println("\n Enter the name of the employee : ");
			name=sc.nextLine();
			System.out.println("\n Enter the mobile number of the employee :");
			mobile_no=sc.nextLine();
			if(mobile_no.length()>10 || mobile_no.length()<10)
			{
				throw new mobile_limit_exception("MOBILE NUMBER MUST BE 10 DIGITS ONLY");
			}

			System.out.println("\n Enter the date of birth of the employee:");
			birth_date=sc.nextLine();

			System.out.println("\n Enter the salary of the employee:");
			salary=sc.nextFloat();
			if(salary<=0)
			{
				throw new salary_exception("SALARY MUST BE GREATER THAN ZERO");
			}

            System.out.println("\n Enter the age of employee:");
            age=sc.nextInt();
			if(age<18)
			{
			   	throw new age_limit_exception("EMPLOYEE AGE SHOULD BE GREATER THAN 18");
			}
        }
		catch(mobile_limit_exception obj)
		{
			System.out.println(obj);
			accept();
		}
		catch(salary_exception e)
		{
			System.out.println(e);
			accept();
		}
		catch(age_limit_exception a)
		{
			System.out.println(a);
			accept();
		}
	}

	public void display()
	{
		System.out.println("\n ********* Employee Info ******** ");
		System.out.println("\n NAME          :"+name);
		System.out.println("\n DATE OF BIRTH :"+birth_date);
		System.out.println("\n AGE           :"+age);
		System.out.println("\n MOBILE NUMBER :"+mobile_no);
		System.out.println("\n SALARY        :"+salary);
		System.out.println("\n ================================");
	}
};

class AssignmentNo13
{
	public static void main(String args[])throws NullPointerException		//main method throws null pointer exception
	{
		int n;
		System.out.println("\n How many employees do you want to insert :");
		Scanner sc=new Scanner(System.in);
		try
		{
			n=sc.nextInt();
			if(n>5)
			{
				throw new array_limit_out_of_bound_exception(" MORE THAN FIVE EXCEPTION CANNOT BE GENERATED ");
			}
        }

        catch(array_limit_out_of_bound_exception a2)
        {
            System.out.println(a2);
            System.out.println("\n enter the number of entries again :");
            n=sc.nextInt();
        }

         Employee emp[]=new Employee[n];
         for(int i=0;i<n;i++)
         {
              emp[i]=new Employee();
              emp[i].accept();
         }
         System.out.println("\n ====== DISPLAYING INFORMATION ======");

         for(int i=0;i<n;i++)
         {
              emp[i].display();
         }
	 }
};
/*
output:
 How many employees do you want to insert :
7
array_limit_out_of_bound_exception:  MORE THAN FIVE EXCEPTION CANNOT BE GENERATED 

 enter the number of entries again :
2

 Enter the name of the employee : 
akash

 Enter the mobile number of the employee :
4355
mobile_limit_exception: MOBILE NUMBER MUST BE 10 DIGITS ONLY

 Enter the name of the employee : 
akash

 Enter the mobile number of the employee :
9999999999

 Enter the date of birth of the employee:
01-03-2000

 Enter the salary of the employee:
70000

 Enter the age of employee:
16
age_limit_exception: EMPLOYEE AGE SHOULD BE GREATER THAN 18

 Enter the name of the employee : 
akash

 Enter the mobile number of the employee :
9999999999

 Enter the date of birth of the employee:
01-03-2000

 Enter the salary of the employee:
700000

 Enter the age of employee:
20

 Enter the name of the employee : 
sham

 Enter the mobile number of the employee :
8989767896

 Enter the date of birth of the employee:
21-02-2000

 Enter the salary of the employee:
454556

 Enter the age of employee:
40

 ====== DISPLAYING INFORMATION ======

 ********* Employee Info ******** 

 NAME          :akash

 DATE OF BIRTH :01-03-2000

 AGE           :20

 MOBILE NUMBER :9999999999

 SALARY        :700000.0

 ================================

 ********* Employee Info ******** 

 NAME          :sham

 DATE OF BIRTH :21-02-2000

 AGE           :40

 MOBILE NUMBER :8989767896

 SALARY        :454556.0

 ================================
*/
