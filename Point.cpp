//******************************************************************************
//  Point.cpp
//  Polymorphism
//
//  Created by Karlina Beringer on July 8, 2014.
//
//  This source file contains the Point class definition.
//  Point is included in Polymorphism through composition.
//******************************************************************************

#include "Point.h"

// Default constructor creates a Point at the graph origin.
Point::Point()
{
    X_coordinate = 0.0;
    Y_coordinate = 0.0;
}

// Normal constructor creates a custom Point object.
Point::Point( double X, double Y )
{
    X_coordinate = X;
    Y_coordinate = Y;
}

// Copy constructor creates a clone of a Point object.
Point::Point( Point & point )
{
    X_coordinate = point.X_coordinate;
    Y_coordinate = point.Y_coordinate;
}

// Setter changes the value of the X_coordinate.
void Point::setX( double X )
{
    X_coordinate = X;
}

// Setter changes the value of the Y_coordinate.
void Point::setY( double Y )
{
    Y_coordinate = Y;
}

// Getter returns the value of the X_coordinate.
double Point::getX()
{
    return X_coordinate;
}

// Getter returns the value of the Y_coordinate.
double Point::getY()
{
    return Y_coordinate;
}

// Getter computes the distance between this and another Point.
// Distance = Square_Root[ ((X2 - X1)^2) + ((X2 - X1)^2) ]
double Point::getDistance( Point & point )
{
    return sqrt( pow(X_coordinate - point.X_coordinate, 2) +
                pow(Y_coordinate - point.Y_coordinate, 2));
}

// Getter computes the slope between this and another Point.
// Slope = (Y2 - Y1) / (X2 - X1)
double Point::getSlope( Point & point )
{
    if (X_coordinate == point.X_coordinate) return INFINITY;
    return (Y_coordinate - point.Y_coordinate)/
    (X_coordinate - point.X_coordinate);
}

// Getter prints the coordinate pair of Point in the form ( X, Y ).
// If no ostream parameter is supplied, default will be cout.
void Point::print( ostream & output )
{
    output << "(" << X_coordinate << "," << Y_coordinate << ")";
}

// Friend function behaves like Points's print method.
// Overloads the ostream operator.
// Friend is NOT a member of Point, but has access to its members.
ostream & operator << ( ostream & output, Point & point )
{
    point.print( output );
    return output;
}

//******************************************************************************
// End of File
//******************************************************************************
