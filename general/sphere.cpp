#include "sphere.h"
#include <iostream>

using namespace std;


//====Constructeur: une sphère est simplement construite à partir de sa position et son rayon

Sphere::Sphere(SupportADessin* support, Vector3D const& pos, double const& rad)
    : Obstacle(support,pos), rayon(rad)
{}

//  Le point le plus proche est l'intersection de la droite qui relie la position du grain et celle de la sphère avec la surface de la sphère

Vector3D Sphere::point_plus_proche(Vector3D const& vect) const {
    Vector3D v(vect-position);
    v = position + (rayon * v.normalise());
    return v;
}


ostream& Sphere::affiche(std::ostream& out) const {
    out<<"Sphere : [pos:  " << position << ", rayon: " << rayon
        << "]";
    return out;

}

void Sphere::dessine() {
    if(support != nullptr) support->dessine(*this);
}

