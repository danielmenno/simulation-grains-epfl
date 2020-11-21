#include "dalle.h"
#include "plan.h"

#include <iostream>

using namespace std;


//====Constructeur: prend un vecteur normale, 2 dimension et un autre vecteur unitaire (le dernier étant calculé par le produit vectoriel)

Dalle::Dalle(SupportADessin* support, Vector3D const& pos, Vector3D const& normal, double length, double width,Vector3D const& unit_length)
    : Plan(support,pos,normal), longueur(length), largeur(width), long_unit(unit_length), larg_unit(normale ^ unit_length)
{}


//Calcul du point le plus proche: appelle la fonction point_plus_proche dans la classe Plan, et puis vérifie si le point renvoyé est sur la dalle ou non

Vector3D Dalle::point_plus_proche(Vector3D const& x1) const {

    Vector3D x2 = Plan::point_plus_proche(x1);

    double xkL = (x2 - position) * long_unit;
    double xkl = (x2 - position) * larg_unit;

    if(xkL > longueur) x2 -= ((xkL - longueur) * long_unit);
    if(xkL < 0) x2 -= (xkL * long_unit);

    if(xkl > largeur) x2 -= ((xkl - largeur) * larg_unit);
    if(xkl < 0) x2 -= (xkl * larg_unit);

    return x2;
}

//Renvoye le point au centre de la dalle (sert à faciliter le dessin)

Vector3D Dalle::centre() const {
    return (position + (longueur/2) * long_unit + (largeur/2) * larg_unit);
}


ostream& Dalle::affiche(ostream& out) const {
    out << "Dalle: [pos: "<< position << ", normale: " << normale << ", longueur: " << longueur
         << ", largeur: "<< largeur << "]" << endl;
    return out;
}


void Dalle::dessine() {
    if(support != nullptr) support->dessine(*this);
}
