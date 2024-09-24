#include <sstream>
#include <typeinfo>
#include "point.hpp"

Point::Point(){
    x=0;
    y=0;
}
Point::Point(double x, double y):x(x),y(y){}

Point::~Point()
{
}

std::ostream& operator<<(std::ostream & e,const Point& f){
    return f.afficher(e);
};
double Point::getx()const{
        return x;
    }
double Point::gety()const{
        return y;
    }