//************************************************************
//  Polygon.h
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This header file contains the declaration for Polygon.
//  Polygon is an abstract class.
//  An abstract class has AT LEAST one virtual function.
//  Polygon also includes Point via composition.
//************************************************************

#ifndef Polygon_h
#define Polygon_h
#include "Point.h"

//------------------------------------------------------------
// Let Polygon be a generic "template" for cyclic polygons.
//------------------------------------------------------------
class Polygon
{
protected:
    
    // Type is a description of the Polygon instance.
    const string TYPE = "POLYGON";
    
    // Color is an arbitrary value.
    // It's being used to demonstrate abstract constructors.
    string color;
    
public:
    
    // Default constructor initializes the color.
    // We cannot instantiate Polygon since it's abstract.
    // Instead, the constructor is used by descendants.
    Polygon();
    
    // Getter method prints a description of the Polygon.
    // If no parameter is supplied, output goes to console.
    void print( ostream & output = cout );
    
    // Friend function alternative to the print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access.
    friend ostream & operator << (ostream & out, Polygon & P);
    
    //--------------------------------------------------------
    // Virtual methods must be defined by derived classes.
    //--------------------------------------------------------
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

#endif

//************************************************************
// End of File
//************************************************************
