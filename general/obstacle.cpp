#include "obstacle.h"
#include "grain.h"

using namespace std;
using namespace physics;



Obstacle::Obstacle(SupportADessin* support, Vector3D const& pos, const Vector3D & vit, bool mov)
    : Dessinable(support), position(pos), vitesse(vit), mouvement(mov)

{}

//Surcharge de l'opérateur d'affichage utilisé polymorphiquement par toutes les sous-classe d'Obstacle

ostream& operator <<(std::ostream& out, Obstacle const& o) {
    return o.affiche(out);
}

void Obstacle::move(const double &dt) {
    if(mouvement) position += dt * vitesse;
}


