//**********************************************************************
//  Triangle.h
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This header file contains the declaration for Triangle.
//  Triangle is a descendant of the abstract class, Polygon.
//**********************************************************************

#ifndef Triangle_h
#define Triangle_h

#include "Polygon.h"

//----------------------------------------------------------------------
// Let Triangle be a three-sided polygon.
//----------------------------------------------------------------------
class Triangle: public Polygon
{
protected:
    
    // Type is a description of the Triangle instance.
    const string TYPE = "POLYGON/TRIANGLE";
    
    // A, B, and C represent points on a plane.
    Point A, B, C;
    
    // Helper method uses the Triangle Inequality to determine
    // whether side legnths a, b, and c form a triangle:
    //    If the following conditions are true...
    //        a + b > c
    //        a + c > b
    //        b + c > a
    //    Then a, b, and c form the side lengths of a triangle.
    bool isTriangle();
    
public:
    
    // Default constructor calls Polygon's constructor.
    // Initializes color to "orange" and points to
    // A(0,0), B(0,3), C(4,0).
    Triangle();
    
    // Normal constructor sets the vertices and color.
    Triangle( string color, Point A, Point B, Point C );
    
    // Copy constructor creates a clone of given Triangle.
    Triangle( Triangle & copy );
    
    // This method overrides Polygon's print method.
    // Getter method prints a description of the Triangle.
    // If no parameter is supplied, output goes to console.
    void print( ostream & output = cout );
    
    // Friend function alternative to the print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access.
    friend ostream & operator << ( ostream & out, Triangle & T );
    
    //------------------------------------------------------------------
    // Implements Polygon's virtual methods.
    //------------------------------------------------------------------
    double getArea();
    double getPerimeter();
};


#endif

//**********************************************************************
// End of File
//**********************************************************************
