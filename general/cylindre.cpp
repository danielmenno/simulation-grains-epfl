#include "cylindre.h"
#include <cmath>
#include <algorithm>  //Pour utiliser la fonction min(a,b) qui rertourne le plus petit des deux. #laziness

//=====Constructeur: prend un rayon, une hauteur et un normale (le long de l'axe de rotation). NB: la position est à moitié hauteur du cylindre

Cylindre::Cylindre(SupportADessin* support, Vector3D const& pos, double radius, double height, Vector3D const& normal)
    :Obstacle(support,pos), rayon(radius), hauteur(height), normale(normal.normalise())
{}

//=====Calcul du point le plus proche selon selon l'algorithme du complément mathématique=====

Vector3D Cylindre::point_plus_proche(Vector3D const& x1) const {

    Vector3D e(x1-position);
    Vector3D en((e*normale)*normale);
    Vector3D n(en.normalise());
    Vector3D eu(e-en);
    Vector3D u(eu.normalise());


    if(std::abs(e*n) >= hauteur/2 || eu.norme2() >= rayon) {
        if(std::abs((e*normale)) < hauteur/2) return (position + en + (rayon * u));
        else {
            return position + (hauteur/2) * n + std::min(rayon,eu.norme()) * u;
        }
    }
    return position; //si le grain est à l'intérieur (impossible) il renvoie la positon du cylindre
}


std::ostream& Cylindre::affiche(std::ostream& flot) const {
    flot << "Cylindre: [po: " << position << ", hauteur: " << hauteur << "]" << std::endl;
    return flot;
}

void Cylindre::dessine() {
    if(support != nullptr) support->dessine(*this);
}
