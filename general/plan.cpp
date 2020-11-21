#include "plan.h"
#include <iostream>

using namespace std;
using namespace physics;

//======Constructeur: le plan est défini par sa position et son vecteur normal (normalisé pour faciliter les calculs)

Plan::Plan(SupportADessin* support, Vector3D const& pos, Vector3D const& unit)
    : Obstacle(support, pos) , normale(unit.normalise())
{}


//Calcul du point le plus proche: simple projection de la position du grain sur le plan
Vector3D Plan::point_plus_proche(Vector3D const& vect) const {
    Vector3D v;
    v = vect + ((position - vect) * normale) * normale;
    return v;
}

//Calcul de la distance entre le grain et le point le plus proche sur le plan ------> INUTILE
Vector3D Plan::distance(Vector3D const& vect) const {

    return (vect - point_plus_proche(vect));
}

void Plan::dessine() {
    if(support != nullptr) support->dessine(*this);
}

//INUTILE
void Plan::aff_point_proche(Vector3D const& vect) const {

    cout << "Point plus proche à " << vect <<" : " << point_plus_proche(vect) << endl;

}

ostream& Plan::affiche(ostream& out) const {
    out << "Plan : [pos: " << position << ", normale: " << normale << "]" << endl;
    return out;
}


