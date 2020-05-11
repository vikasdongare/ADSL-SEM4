/*
											ASSIGNMENT NO:12
	
Assignment STATEMENT:Create a drawing consists of multiple shapes. Create an Abstract base class Shape and define all the 						methods that different types of Shape objects will implement. 
					draw() to draw the shape and 
					Area() that will return the area of the shape.
					Perimeter() will return perimeter of shape
					Different shapes are rectangle, circle,triangle, rhombus etc 
					Create a drawing consists of multiple shapes. Create an Interface for Shape and define all the methods 						that different types of Shape for above.
							
Name   :- Vikas Laxman Dongare
SUB    :- ADSL
ROLL NO:- 15
CLASS  :- SE
DIV    :- B

*/

import java.util.*;

abstract class shape{

	String object_name=" ";
	shape(String name)
	{
		this.object_name=name;
	}

	abstract public void draw();
	abstract public double area();
	abstract public double perimeter();

};

class rectangle extends shape{					//extends keyword used for inheritance

	int lenght,breadth;
	rectangle(int lenght,int breadth,String name)		//this keyword used to refer to the field variables
	{
		super(name);
		this.lenght=lenght;
		this.breadth=breadth;
	}
	public void draw()
	{
		System.out.println("\n RECTANGLE IS BEEN DRAWN ");
	}
	public double area()
	{
		double area_rectangle;
		area_rectangle=lenght*breadth;
		return area_rectangle;
	}
	public double perimeter()
	{
		double perimeter_rectangle;
		perimeter_rectangle=2*(lenght+breadth);
		return perimeter_rectangle;
	}

};//end of rectangle class

class circle extends shape{

	int radius;
	double pi=3.14;
	circle(int radius,String name)		//this keyword used to refer to the field variables
	{
		super(name);
		this.radius=radius;
	}
	public void draw()
	{
		System.out.println("\n CIRCLE IS BEEN DRAWN ");
	}
	public double area()
	{
		double area_circle;
		area_circle=(pi*radius*radius);
		return area_circle;
	}
	public double perimeter()
	{
		double perimeter_circle;
		perimeter_circle=2*pi*radius;
		return perimeter_circle;
	}

};//end of circle class

class traingle extends shape{

	int base,height,a,c;
	double pi=3.14;
	traingle(int a,int base,int c,int height,String name)		//this keyword used to refer to the field variables
	{
		super(name);
		this.a=a;
		this.base=base;
		this.c=c;
		this.height=height;
	}
	public void draw()
	{
		System.out.println("\n TRIANGLE IS BEEN DRAWN ");
	}
	public double area()
	{
		double area_traingle;
		area_traingle=(0.5*base*height);
		return area_traingle;
	}
	public double perimeter()
	{
		double perimeter_traingle;
		perimeter_traingle=a+base+c;
		return perimeter_traingle;
	}

};//end of traingle class

class rhombus extends shape{

	int d1,d2;
	double pi=3.14;
	rhombus(int d1,int d2,String name)		//this keyword used to refer to the field variables
	{
		super(name);
		this.d1=d1;
		this.d2=d2;
	}
	public void draw()
	{
		System.out.println("\n RHOMBUS IS BEEN DRAWN ");
	}
	public double area()
	{
		double area_rhombus;
		area_rhombus=(0.5*d1*d2);
		return area_rhombus;
	}
	public double perimeter()
	{
		double perimeter_rhombus;
		perimeter_rhombus=(2*Math.sqrt(Math.pow(d1,2)+Math.pow(d2,2)));
		return perimeter_rhombus;
	}

};//end of rhombus class

class AssignmentNo12
{
	public static void main(String args[])
	{
		System.out.println("\n RECTANGLE ");
		shape rect=new rectangle(2,3,"rectangle");			//passing instance of rectangle class to base class shape
		rect.draw();
		System.out.println("\n AREA OF RECTANGLE:"+rect.area());
		System.out.println("\n PERIMETER OF RECTANGLE:"+rect.perimeter());
		System.out.println("\n -------------------------");

		System.out.println("\n CIRCLE");
		shape cir=new circle(3,"circle");
		cir.draw();
		System.out.println("\n AREA OF CIRCLE:"+cir.area());
		System.out.println("\n PERIMETER OF CIRCLE:"+cir.perimeter());
		System.out.println("\n -------------------------");

		System.out.println("\n TRAINGLE");
		shape traingle1=new traingle(2,3,5,4,"traingle");
		traingle1.draw();
		System.out.println("\n AREA OF TRAINGLE:"+traingle1.area());
		System.out.println("\n PERIMETER OF TRAINGLE:"+traingle1.perimeter());
		System.out.println("\n -------------------------");

		System.out.println("\n RHOMBUS");
		shape rhomb=new rhombus(4,5,"rhombus");
		rhomb.draw();
		System.out.println("\n AREA OF RHOMBUS:"+rhomb.area());
		System.out.println("\n PERIMETER OF RHOMBUS:"+rhomb.perimeter());
		System.out.println("\n -------------------------");
	}
}

/*

OUTPUT:

 RECTANGLE

 RECTANGLE IS BEEN DRAWN

 AREA OF RECTANGLE:6.0

 PERIMETER OF RECTANGLE:10.0

 -------------------------

 CIRCLE

 CIRCLE IS BEEN DRAWN

 AREA OF CIRCLE:28.259999999999998

 PERIMETER OF CIRCLE:18.84

 -------------------------

 TRAINGLE

 TRIANGLE IS BEEN DRAWN

 AREA OF TRAINGLE:6.0

 PERIMETER OF TRAINGLE:10.0

 -------------------------

 RHOMBUS

 RHOMBUS IS BEEN DRAWN

 AREA OF RHOMBUS:10.0

 PERIMETER OF RHOMBUS:12.806248474865697

 -------------------------

*/
