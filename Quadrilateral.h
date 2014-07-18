//**********************************************************************
//  Quadrilateral.h
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This header file contains the declaration for Quadrilateral.
//  Quadrilateral is a descendant of the abstract class, Polygon.
//**********************************************************************

#ifndef Quadrilateral_h
#define Quadrilateral_h

#include "Polygon.h"

//----------------------------------------------------------------------
// Let Quadrilateral be a four-sided cyclic polygon.
//----------------------------------------------------------------------
class Quadrilateral: public Polygon
{
protected:
    
    // Type is a description of the Triangle instance.
    const string TYPE = "POLYGON/QUADRILATERAL";
    
    // A, B, C, and D represent points on a plane
    Point A, B, C, D;
    
    // Helper method uses Ptolemy's Theorem to determine whether
    // points A, B, C, and D form a cyclic quadrilateral:
    //    If the following condition is true:
    //           AB × CD + BC × DA = AC × BD,
    //           where AB,BC, CD, and DA are side lengths,
    //    Then A, B, C, and D form a cyclic quadrilateral.
    bool isCyclicQuadrilateral();
    
public:
    
    // Default constructor calls Polygon's constructor.
    // Initializes color to "orange" and vertices to
    // A(0,0), B(0,5), C(4,5), D(4,0).
    Quadrilateral();
    
    // Normal constructor sets the vertices and color.
    Quadrilateral(string color, Point A, Point B, Point C, Point D);
    
    // Copy constructor creates a clone of given Quadrilateral.
    Quadrilateral( Quadrilateral & copy );
    
    // This method overrides Polygon's print method.
    // Getter method prints a description of the Quadrilateral.
    // If no parameter is supplied, output goes to console.
    void print( ostream & output = cout );
    
    // Friend function alternative to the print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access.
    friend ostream & operator << ( ostream & out, Quadrilateral & Q );
    
    //------------------------------------------------------------------
    // Implements Polygon's virtual methods.
    //------------------------------------------------------------------
    double getArea();
    double getPerimeter();
};


#endif

//************************************************************
// End of File
//************************************************************
