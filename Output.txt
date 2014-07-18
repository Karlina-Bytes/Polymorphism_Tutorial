//************************************************************
//  main.cpp
//  Polymorphism_Project
//
//  Created by Karlina Beringer on July 13, 2014.
//
//  This driver file implements the abstract class, Polygon.
//  It also implements descendants, Triangle and Rectangle.
//  This program demonstrates polymorphism in C++.
//************************************************************

#include "Polygon.h"
#include "Triangle.h"
#include "Quadrilateral.h"

#include <ctime>
#include <cstdlib>

int main()
{
    //--------------------------------------------------------
    // The statement below would cause an error.
    // Abstract classes CANNOT be instantiated directly.
    //--------------------------------------------------------
    // Polygon polygon;

    //--------------------------------------------------------
    // Although we cannot create instances of Polygon,
    // we can create pointer of type Polygon.
    // These pointers can reference instances of
    // the Rectangle and Quadrilateral classes.
    //--------------------------------------------------------
    Polygon * polygon;
    
    //--------------------------------------------------------
    // Create a default Triangle object, trig1.
    //--------------------------------------------------------
    cout << "Create a default Triangle object, trig1...\n";
    Triangle trig1;
    cout << trig1;
    
    //--------------------------------------------------------
    // Create a custom Triangle object, trig2.
    //--------------------------------------------------------
    cout << "Create a custom Triangle object, trig2...\n";
    Point A( -1, -1 ), B( 0, 10 ), C( -6, 6 );
    Triangle trig2( "blue", A, B, C );
    cout << trig2;
    
    //--------------------------------------------------------
    // Create a copy of trig2 called trig3.
    //--------------------------------------------------------
    cout << "Create a copy of trig2 called trig3...\n";
    Triangle trig3( trig2 );
    cout << trig3;
    
    //--------------------------------------------------------
    // Use pointer of type Polygon to access trig3.
    //--------------------------------------------------------
    cout << "Use pointer of type Polygon to access trig3.\n";
    cout << "Notice that Polygon's print method is called...\n";
    polygon = &trig3;
    cout << *polygon;
    
    //--------------------------------------------------------
    // Use pointer of type Triangle to access trig3.
    //--------------------------------------------------------
    cout << "Use pointer of type Triangle to access trig3.\n";
    cout << "Notice that Triangle's print method is called...\n";
    Triangle * triangle = &trig3;
    cout << *triangle;
    
    //--------------------------------------------------------
    // Create a default Quadrilateral object, quad1.
    //--------------------------------------------------------
    cout << "Create a default Quadrilateral object, quad1....\n";
    Quadrilateral quad1;
    cout << quad1;
    
    //--------------------------------------------------------
    // Create a custom Triangle object, trig2.
    //--------------------------------------------------------
    cout << "Create a custom Triangle object, trig2.\n";
    cout << "Randomly generate four points...\n";
    srand (time(NULL));
    double randomValues[8];
    for (int i = 0; i < 8; i++)
        randomValues[i] = rand() % 100;
    Point W( randomValues[0], randomValues[1] );
    Point X( randomValues[2], randomValues[3] );
    Point Y( randomValues[4], randomValues[5] );
    Point Z( randomValues[6], randomValues[7] );
    Quadrilateral quad2( "green", W, X, Y, Z );
    cout << quad2;
    
    return 0;
}
//************************************************************
// End of File
//************************************************************

