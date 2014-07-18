//*************************************************************************
//  Point.h
//  Polymorphism
//
//  Created by Karlina Beringer on July 8, 2014.
//
//  This header file contains the Point class declaration.
//  Point is included in Polygon through composition.
//*************************************************************************

#ifndef Point_h
#define Point_h

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//------------------------------------------------------------------
// Point represents a coordinate pair on a two-dimensional plane.
//------------------------------------------------------------------
class Point
{
private:
    
    // X and Y coordinates describe a point on a plane.
    double X_coordinate, Y_coordinate;
    
public:
    
    // Default constructor creates a Point at the graph origin.
    Point();
    
    // Normal constructor creates a custom Point object.
    Point( double X, double Y );
    
    // Copy constructor creates a clone of a Point object.
    Point( Point & point );
    
    // Setter changes the value of the X_coordinate.
    void setX( double X );
    
    // Setter changes the value of the Y_coordinate.
    void setY( double Y );
    
    // Getter returns the value of the X_coordinate.
    double getX();
    
    // Getter returns the value of the Y_coordinate.
    double getY();
    
    // Getter computes the distance between this and another Point.
    // Distance = Square_Root[ ((X2 - X1)^2) + ((X2 - X1)^2) ]
    double getDistance( Point & point );
    
    // Getter computes the slope between this and another Point.
    // Slope = (Y2 - Y1) / (X2 - X1)
    double getSlope( Point & point );
    
    // Getter prints the coordinate pair of Point in the form ( X, Y ).
    // If no ostream parameter is supplied, default will be cout.
    void print( ostream & output = cout );
    
    // Friend function behaves like Points's print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of Point, but has access to its members.
    friend ostream & operator << ( ostream & output, Point & point );
};

#endif

//******************************************************************************
// End of File
//******************************************************************************
