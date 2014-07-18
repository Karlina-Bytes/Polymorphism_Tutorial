//************************************************************
//  Polygon.cpp
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This header file defines methods of the Polygon class.
//  Polygon is an abstract class.
//  An abstract class has AT LEAST one virtual function.
//************************************************************

#include "Polygon.h"

// Default constructor initializes the color.
// We cannot instantiate Polygon since it's abstract.
// Instead, the constructor is used by descendants.
Polygon::Polygon()
{
    color = "orange";
}

// Getter method prints a description of the Polygon.
// If no parameter is supplied, output goes to console.
void Polygon::print( ostream & output )
{
    output << "\t" << TYPE << "\n\t{\n";
    output << "\t\tcolor = " << color << "\n\t}\n\n";
}

// Friend function alternative to the print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access.
ostream & operator << (ostream & out, Polygon & P)
{
    P.print( out );
    return out;
}

//--------------------------------------------------------
// Virtual methods must be defined by derived classes.
//--------------------------------------------------------
double Polygon::getArea() { return 0.0; }
double Polygon::getPerimeter() { return 0.0; }

//************************************************************
// End of File
//************************************************************
