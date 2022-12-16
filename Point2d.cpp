#include "Point2d.h"
#include <iostream>
#include <cmath>
using namespace std;
    
    Point2d::Point2d(){
        x = 0;
        y = 0;
    }
    Point2d::Point2d(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }
/*Point2d::~Point2d(){
	cout << "Point2d Destructed" << endl;
}*/
