#ifndef __Polaire__
#define __Polaire__

#include "point.hpp"
#include "cartesien.hpp"
#include "nuage.hpp"

class Nuage;

class Cartesien;

class Polaire : public Point
{
public:
    Polaire();
    Polaire(double,double);
    Polaire(const Cartesien&);
    std::ostream& afficher(std::ostream&)const;
    double getAngle()const;
    double getDistance()const;
    void setAngle(double b);
    void setDistance(double h);
    ~Polaire();
    void convertir(Polaire&)const;
    void convertir(Cartesien&)const;
};
class BarycentrePolaire
{
    public:
        Polaire operator()(const Nuage&);
};






#endif