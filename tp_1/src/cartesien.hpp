#ifndef __Cartesien__
#define __Cartesien__
#include "point.hpp"
#include "polaire.hpp"

class Polaire;

class Cartesien : public Point
{

public:
    Cartesien();
    Cartesien(Polaire &);
    Cartesien(double ,double);
    double getX()const;
    void setX(double);
    void setY(double);
    double getY()const;
    std::ostream& afficher(std::ostream&)const;
    ~Cartesien();
    void convertir(Polaire&)const;
    void convertir(Cartesien&)const;
};






#endif