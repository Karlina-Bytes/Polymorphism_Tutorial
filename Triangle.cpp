//**********************************************************************
//  Triangle.cpp
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This source file defines methods of the Triangle class.
//  Triangle is a descendant of the abstract class, Polygon.
//**********************************************************************

#include "Triangle.h"

// Helper method uses the Triangle Inequality to determine
// whether side legnths a, b, and c form a triangle:
//    If the following conditions are true...
//        a + b > c
//        a + c > b
//        b + c > a
//    Then a, b, and c form the side lengths of a triangle.
bool Triangle::isTriangle()
{
    // Get side lengths.
    double a = C.getDistance( B );
    double b = A.getDistance( C );
    double c = A.getDistance( B );
    
    // Compare side lengths.
    if ( (a + b) < c ) return false;
    if ( (a + c) < b ) return false;
    if ( (b + c) < a ) return false;
    return true;
}

// Default constructor calls Polygon's constructor.
// Initializes color to "orange" and points to
// A(0,0), B(0,3), C(4,0).
Triangle::Triangle(): Polygon()
{
    A = Point( 0, 0 );
    B = Point( 0, 3 );
    C = Point( 4, 0 );
}

// Normal constructor sets the vertices and color.
Triangle::Triangle( string color, Point A, Point B, Point C )
{
    if ( isTriangle() )
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
    }
    else
    {
        this -> A = Point( 0, 0 );
        this -> B = Point( 0, 3 );
        this -> C = Point( 4, 0 );
    }
    this -> color = color;
}

// Copy constructor creates a clone of given Triangle.
Triangle::Triangle( Triangle & copy )
{
    this -> A = copy.A;
    this -> B = copy.B;
    this -> C = copy.C;
    this -> color = copy.color;
}

// This method overrides Polygon's print method.
// Getter method prints a description of the Triangle.
// If no parameter is supplied, output goes to console.
void Triangle::print( ostream & output )
{
    output << "\t" << TYPE << "\n\t{\n";
    output << "\t\tcolor = " << color << "\n";
    output << "\t\tA = " << A << "\n";
    output << "\t\tB = " << B << "\n";
    output << "\t\tC = " << C << "\n";
    output << "\t\tside a = BC = " << B.getDistance(C) << "\n";
    output << "\t\tside b = AC = " << A.getDistance(C) << "\n";
    output << "\t\tside c = AB = " << A.getDistance(B) << "\n";
    output << "\t\tperimeter = " << getPerimeter() << "\n";
    output << "\t\tarea = " << getArea() << "\n\t}\n\n";
    
}

// Friend function alternative to the print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access.
ostream & operator << ( ostream & out, Triangle & T )
{
    T.print( out );
    return out;
}

// Getter returns the area of the triangle using Heron's Formula:
// Area = sqrt( s * (s - a) * (s - b) * (s - c) ),
// where s = (1/2) * (a + b + c)
double Triangle::getArea()
{
    // Get side lengths.
    double a = C.getDistance( B );
    double b = A.getDistance( C );
    double c = A.getDistance( B );
    
    // Compute the area using Heron's Formula.
    double s = 0.5 * ( a + b + c );
    return sqrt( s * (s - a) * (s - b) * (s - c) );
}

// Getter returns the perimeter of the triangle.
// Perimeter = sum of all side lengths
double Triangle::getPerimeter()
{
    // Get side lengths.
    double a = C.getDistance( B );
    double b = A.getDistance( C );
    double c = A.getDistance( B );
    
    // Add up the side lengths.
    return a + b + c;
}

//**********************************************************************
// End of File
//**********************************************************************
