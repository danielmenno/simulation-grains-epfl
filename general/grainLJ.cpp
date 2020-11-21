#include <cmath>
#include "grainLJ.h"


//cf le .h pour les commentaires


//déclaration de valeurs de constantes en "static"
double GrainLJ::sigma = 0.885;
double GrainLJ::epsilon = 25;

//Méthode utilisée pour le calcule de force entre le grain et d'autres grains + obstacles
double GrainLJ::forceLJ_function(double const& x) const {
    if(x <= 1) return -1;
    if(x >= 2) return 0;
    return (pow(x,6)-2)/pow(x,13);
}


//Ajustement de la position du grain si il est trop proche d'un autre, i.e. si la distance entre leurs positions < la somme des 2 rayons
void GrainLJ::adjust_position(Vector3D const& y, double const& r1) {
    double d_min(r1 + rayon);
    if(y.norme() < d_min) {
        Vector3D u = y.normalise();
        x = x-(d_min - y.norme())*u;
        v = v-(v*u)*u;
    }
}


//Calcule l'élément 24*epsilon/(sigma^2) selon la direction de la force
Vector3D GrainLJ::forceLJ(Vector3D const& vect) const {
    Vector3D z = vect.normalise();
    return 24*epsilon/pow(sigma, 2)*z;
}


//Calcul de la force ajoutée à un grain par un obstacle
void GrainLJ::add_f(Obstacle* obstacle) {
    Vector3D y(obstacle->point_plus_proche(x)-x);
    adjust_position(y);
    y = obstacle->point_plus_proche(x)-x;
    f += forceLJ_function(1.09 +(y.norme()-rayon)/sigma)*2*forceLJ(y);
}

//Calcul de la force ajoutée à un grain par un autre grain
void GrainLJ::add_f(Grain* voisin) {
    Vector3D y(voisin->get_po() - x);
    adjust_position(y, voisin->get_r());
    y = voisin->get_po() - x;
    f += forceLJ_function(1.09 +(y.norme()-rayon-voisin->get_r())/sigma)*forceLJ(y);
}

//Méthode qui ajoute simplement une force à l'ensemble des forces appliquée au grain
void GrainLJ::add_f(Vector3D const& vect) {
    f += vect;
}

std::ostream& GrainLJ::affiche(std::ostream& out) const {
    out << "[po : "
        << get_po()
        << " v : "
        << get_v()
        << " m : "
        << masse()
        << " r :"
        << get_r()
        << "]"
        << std::endl;
    return out;
}
