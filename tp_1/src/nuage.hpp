#ifndef __Nuage__
#define __Nuage__
#include <vector>
#include "point.hpp"
#include "cartesien.hpp"


class Cartesien ;

class Nuage
{
    private:
        std::vector<Point *> points;
    public:
        Nuage();
        void ajouter(Point& p);
        unsigned int size()const;
        typedef std::vector<Point*>::const_iterator const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        Point barycentre()const;


};
class BarycentreCartesien {
public:
    Cartesien operator()(const Nuage& n) const;
};
Cartesien barycentre(const Nuage& n);










#endif