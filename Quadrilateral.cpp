//**********************************************************************
//  Quadrilateral.cpp
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This source file defines methods of the Quadrilateral class.
//  Quadrilateral is a descendant of the abstract class, Polygon.
//**********************************************************************

#include "Quadrilateral.h"

// Helper method uses Ptolemy's Theorem to determine whether
// points A, B, C, and D form a cyclic quadrilateral:
//    If the following condition is true:
//           AB × CD + BC × DA = AC × BD,
//           where AB,BC, CD, and DA are side lengths,
//    Then A, B, C, and D form a cyclic quadrilateral.
bool Quadrilateral::isCyclicQuadrilateral()
{
    // Get side lengths.
    double AB = A.getDistance( B );
    double BC = B.getDistance( C );
    double CD = C.getDistance( D );
    double DA = D.getDistance( A );
    
    // Get diagonals.
    double AC = A.getDistance( C );
    double BD = B.getDistance( D );
    
    // Employ Ptolemy's Theorem.
    if ((AB * CD + BC * DA) == (AC * BD)) return true;
    return false;
}

// Default constructor calls Polygon's constructor.
// Initializes color to "orange" and vertices to
// A(0,0), B(0,5), C(4,5), D(4,0).
Quadrilateral::Quadrilateral(): Polygon()
{
    A = Point( 0, 0 );
    B = Point( 0, 5 );
    C = Point( 4, 5 );
    D = Point( 4, 0 );
}

// Normal constructor sets the vertices and color.
Quadrilateral::Quadrilateral( string color, Point A,
                              Point B, Point C, Point D )
{
    if ( isCyclicQuadrilateral() )
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
        this -> D = D;
    }
    else
    {
        this -> A = Point( 0, 0 );
        this -> B = Point( 0, 5 );
        this -> C = Point( 4, 5 );
        this -> D = Point( 4, 0 );
    }
    this -> color = color;
}

// Copy constructor creates a clone of given Quadrilateral.
Quadrilateral::Quadrilateral( Quadrilateral & copy )
{
    this -> A = copy.A;
    this -> B = copy.B;
    this -> C = copy.C;
    this -> D = copy.D;
    this -> color = copy.color;
}

// This method overrides Polygon's print method.
// Getter method prints a description of the Quadrilateral.
// If no parameter is supplied, output goes to console.
void Quadrilateral::print( ostream & output )
{
    output << "\t" << TYPE << "\n\t{\n";
    output << "\t\tcolor = " << color << "\n";
    output << "\t\tA = " << A << "\n";
    output << "\t\tB = " << B << "\n";
    output << "\t\tC = " << C << "\n";
    output << "\t\tD = " << D << "\n";
    output << "\t\tAB = " << A.getDistance(B) << "\n";
    output << "\t\tBC = " << B.getDistance(C) << "\n";
    output << "\t\tCD = " << C.getDistance(D) << "\n";
    output << "\t\tDA = " << D.getDistance(A) << "\n";
    output << "\t\tAC = " << A.getDistance(C) << "\n";
    output << "\t\tBD = " << B.getDistance(D) << "\n";
    output << "\t\tperimeter = " << getPerimeter() << "\n";
    output << "\t\tarea = " << getArea() << "\n\t}\n\n";
}

// Friend function alternative to the print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access.
ostream & operator << ( ostream & out, Quadrilateral & Q )
{
    Q.print( out );
    return out;
}

// Getter returns the area of the triangle using Heron's Formula:
// First, divide the quadrilateral into two triangles.
// Next, compute the area of each triangle:
//     Area = sqrt( s * (s - a) * (s - b) * (s - c) ),
//     where s = (1/2) * (a + b + c)
// Finally, add up the areas of the triangles to get the total
// area of the quadrilateral.
double Quadrilateral::getArea()
{
    // First Triangle
    double AB = A.getDistance( B );
    double BC = B.getDistance( C );
    double CA = C.getDistance( A );
    
    // Second Triangle
    double AC = A.getDistance( C );
    double CD = C.getDistance( D );
    double DA = D.getDistance( A );
    
    // Compute half the perimeters.
    double S1 = ( AB + BC + CA ) / 2;
    double S2 = ( AC + CD + DA ) / 2;
    
    // Compute the areas using Heron's formula.
    double A1 = sqrt( S1*( S1-AB )*( S1-BC )*( S1-CA ));
    double A2 = sqrt( S2*( S2-AC )*( S2-CD )*( S2-DA ));
    
    // Return the sum of the two triangles.
    return A1 + A2;
}

// Getter returns the perimeter of the Quadrilateral
// Perimeter = sum of all side lengths
double Quadrilateral::getPerimeter()
{
    // Get side lengths.
    double AB = A.getDistance( B );
    double BC = B.getDistance( C );
    double CD = C.getDistance( D );
    double DA = D.getDistance( A );
    
    // Add the side lengths.
    return AB + BC + CD + DA;
}

//**********************************************************************
// End of File
//**********************************************************************
