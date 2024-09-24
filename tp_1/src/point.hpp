#ifndef __Point__
#define __Point__


class Cartesien;
class Polaire;

class Point
{
protected:
    double x;
    double y;
   
public:
    Point(double x, double y);
    Point();
    virtual void convertir(Polaire&)const=0;
    virtual void convertir(Cartesien&)const=0;
    double getx()const;
    double gety()const;
    virtual std::ostream& afficher(std::ostream&)const=0;
    virtual ~Point();
    
};

std::ostream& operator<<(std::ostream & e,const Point& f);


#endif