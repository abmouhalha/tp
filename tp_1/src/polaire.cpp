#include <ostream>
#include <iostream>
#include <cmath>
#include "polaire.hpp"

    Polaire::Polaire(double A,double D):Point(A,D){}
    
    Polaire::Polaire():Point(){


    }

    double Polaire::getAngle()const{
        return x;
    }
    double Polaire::getDistance()const{
        return y;
    }
    Polaire::~Polaire(){}
    void Polaire::setAngle(double b){
        x=b;
    }
    void Polaire::setDistance(double h){
        y=h;
    }
    std::ostream& Polaire::afficher(std::ostream& flux)const{
        flux << "(a=" << x <<";d="<< y <<")";
        return flux;
    }
    void Polaire::convertir(Polaire& e)const{
        e.setAngle(this->getAngle());
        e.setDistance(this->getDistance());
       

    }
    void Polaire::convertir(Cartesien& f)const{
        f.setX(y * std::cos(x * M_PI / 180) );
        f.setY(y * std::sin(x * M_PI / 180));

    }
    
Polaire::Polaire(const Cartesien& c){
    x = std::atan2(c.getY(),c.getX())*180/M_PI;
    y = std::hypot(c.getX(),c.getY());

}

Polaire BarycentrePolaire::operator()(const Nuage& n){
    if (n.size() == 0) {
        throw std::runtime_error("Le nuage est vide, impossible de calculer le barycentre");
    }

    double xSum = 0.0;
    double ySum = 0.0;

    for (Nuage::const_iterator it = n.begin(); it != n.end(); ++it) {
        xSum += (*it)->getx();
        ySum += (*it)->gety();
    }

    double xBary = xSum / n.size();
    double yBary = ySum / n.size();



    return Polaire(Cartesien(xBary,yBary));  
    }


