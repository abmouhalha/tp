#include <ostream>
#include <iostream>
#include <cmath>

#include "cartesien.hpp"

Cartesien::Cartesien():Point(){

}

Cartesien::Cartesien(double e,double f)
{
    x=e;
    y=f;
    }
double Cartesien::getX()const{
        return x;
    }
double Cartesien::getY()const{
        return y;
    }
void Cartesien::setX(double a){
    x=a;
}
void Cartesien::setY(double b){
        y=b;
    }
std::ostream& Cartesien::afficher(std::ostream& flux)const{
        flux << "(x=" << x <<";y="<< y <<")";
        return flux;
    }

Cartesien::~Cartesien(){}
void Cartesien::convertir(Polaire& e)const{
    e.setAngle(std::atan2(y,x)*180/M_PI);
    e.setDistance(std::hypot(x,y));

}
void Cartesien::convertir(Cartesien& f)const
{
        f.setX(this->getX());
        f.setY(this->getY());
}

Cartesien::Cartesien(Polaire & p){
    x = p.getDistance() * std::cos(p.getAngle() * M_PI / 180);
    y = p.getDistance() * std::sin(p.getAngle() * M_PI / 180);

}
