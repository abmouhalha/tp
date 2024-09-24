#include <ostream>
#include <vector>
#include <stdexcept>
#include "nuage.hpp"
#include "point.hpp"



Nuage::Nuage(){
    
}
void Nuage::ajouter(Point& p){
    points.push_back(&p);
}

unsigned int Nuage::size()const{
        return points.size();
}

Nuage::const_iterator Nuage::begin() const{
    return points.begin();
}
Nuage::const_iterator Nuage::end() const
{
        return points.end();

}
Cartesien barycentre(const Nuage& n){
    if (n.size() == 0) {
        throw std::runtime_error("Le nuage est vide, impossible de calculer le barycentre");
    }

    double xSum = 0.0;
    double ySum = 0.0;

    // Parcourir tous les points et calculer la somme des coordonnées
    for (Nuage::const_iterator it = n.begin(); it != n.end(); ++it) {
        xSum += (*it)->getx();
        ySum += (*it)->gety();
    }

    // Calcul du barycentre (moyenne des coordonnées)
    double xBary = xSum / n.size();
    double yBary = ySum / n.size();

    return Cartesien(xBary, yBary);

}

Cartesien BarycentreCartesien::operator()(const Nuage& n) const{
    if (n.size() == 0) {
        throw std::runtime_error("Le nuage est vide, impossible de calculer le barycentre");
    }

    double xSum = 0.0;
    double ySum = 0.0;

    // Parcourir tous les points et calculer la somme des coordonnées
    for (Nuage::const_iterator it = n.begin(); it != n.end(); ++it) {
        xSum += (*it)->getx();
        ySum += (*it)->gety();
    }

    // Calcul du barycentre (moyenne des coordonnées)
    double xBary = xSum / n.size();
    double yBary = ySum / n.size();

    return Cartesien(xBary, yBary);

}

