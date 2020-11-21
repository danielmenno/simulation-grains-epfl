#include "brique.h"


//====Constructeur: reçcoit les dimensions de la brique et deux vecteurs unitaires=======
Brique::Brique(SupportADessin* support, Vector3D const& pos, double height, double length, double width,
                    Vector3D const& unit_h, Vector3D const& unit_l)
    :Obstacle(support,pos), hauteur(height), longueur(length), largeur(width), haut_unit(unit_h), long_unit(unit_l.normalise()),
                    larg_unit((haut_unit ^ long_unit).normalise()), normale(haut_unit.normalise())
{}

// Pour le constructeur: la position, les 3 dimension et deux vecteurs unitaires directionels (hauteur & longueur). La largeur est initialisée par
// le produit vectoriel des deux. NB: haut_unit est donné vers le haut pour que le cross marche, mais en vrai la coordonnée de position est placée
// sur la face superieure de la brique. (Donc la vrai hauteur est dans le sens de -haut_unit)


Vector3D Brique::point_plus_proche(Vector3D const& x1) const{
    //vector<double> distances;
    std::vector<Dalle*> faces = get_faces();
    double d0 = distance(faces[0]->point_plus_proche(x1), x1); size_t track = 0;

    //Je défini les 6 faces comme des dalles, pour pouvoir utiliser la fonction distance dans cette classe.

    //Rappel: Dalle est construit ainsi: (positon, normale, longueur, largeur, vect unitaire de longueur)

    //Parcourir tableau - calculer distance à la position x1 - stocker la plus petite distance

    for(size_t i = 0; i < faces.size(); ++i) {
        if(distance(faces[i]->point_plus_proche(x1), x1) < d0) {
            track = i;
            d0 = distance(faces[i]->point_plus_proche(x1),x1);
        }
    }
    Vector3D tmp(faces[track]->point_plus_proche(x1));

    for(auto face : faces) {delete face; face = nullptr;}
    faces.clear();
    return tmp;          //renvoi du point le plus proche
}

std::vector<Dalle*> Brique::get_faces() const {

    std::vector<Dalle*> faces = {};

    Dalle d1(support,position, normale, longueur, largeur, long_unit);  //face d'en haut
    Dalle d2(support,position,-larg_unit, hauteur, longueur, -normale); //face de gauche
    Dalle d3(support,position,-long_unit, largeur, hauteur, larg_unit); //face de devant

    Dalle d4(support,position + (longueur*long_unit), long_unit, hauteur, largeur, -normale); //face de derrière
    Dalle d5(support,position + (largeur*larg_unit), larg_unit, longueur, hauteur, long_unit); //face de droite
    Dalle d6(support,position - (hauteur*normale), -normale, largeur, longueur, larg_unit); //face d'en bas

    faces.push_back(new Dalle(d1)); faces.push_back(new Dalle(d2)); faces.push_back(new Dalle(d3));   //Création d'un tableau avec les 6 faces
    faces.push_back(new Dalle(d4)); faces.push_back(new Dalle(d5)); faces.push_back(new Dalle(d6));

    return faces;
}

std::ostream& Brique::affiche(std::ostream& flot) const {
    flot << "Brique: [po: " << position << ", long: " << longueur <<
            ", larg: " << largeur << ", hauteur: " << hauteur << "]" << std::endl;
    return flot;
}

void Brique::dessine() {
    if(support != nullptr) support->dessine(*this);
}
