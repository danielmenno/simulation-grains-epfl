#include "pyramide.h"
#include <iostream>
#include <vector>
#include <cmath>

//-------------TRIANGLE---------------//
//L'obstacle "Triangle" n'est jamais utilisé en tant que soit, mais sert à construire la pyramide


//=====Constructeur: le triangle est simplement construit à partir de trois points

Triangle::Triangle(SupportADessin* sup, Vector3D const& pos,Vector3D const& pt2, Vector3D const& pt3)
    : Obstacle(sup,pos), p2(pt2), p3(pt3)
{
    normale = ((pt3 - position) ^ hauteur()).normalise();
}


// Cette méthode calcule "l'hauteur du triangle", i.e. la droite qui passe par p2 et est perpendiculaire au côté (p3-position)

Vector3D Triangle::hauteur() const {


    double b = (p2 - position).norme(); double c = (p3-position).norme();
    double cos_a = ((p2-position) * (p3-position)) /(b*c) ;         //calcul du cosinus de l'angle du point position
    return p2 - position - (cos_a * b) * (p3-position).normalise();     //projection du côté (p2-position) sur (p3-position)

}

std::ostream& Triangle::affiche(std::ostream& out) const {
    out << "Triangle de points: " << position << ", " << p2 << ", " << p3 << std::endl;
    return out;
}


void Triangle::dessine() {
    if(support != nullptr) support->dessine(*this);
}

//Méthode qui détermine si deux points sont du même côté d'une droite---elle servira our déterminer si un point se trouve dans un triangle

bool sameSide(Vector3D const& p1, Vector3D const& p2, Vector3D const& a, Vector3D const& b) {
    Vector3D cp1 = (b-a) ^ (p1-a); Vector3D cp2 = (b-a) ^ (p2-a);

    if(cp1*cp2 >= 0) return true;       //si les deux produits vectoriels ont le même signe en x et y les 2 points sont du même côté de la droite
    return false;
}

//Vérifier si un point donné se trouve à l'intérieur du triangle

bool Triangle::inTriangle(Vector3D const& p) const {

    //  Si le point p se trouve du même côté de deux sommets (p1 et p2) que le troisième sommet (p3), et ceci pour tous les trois côtés,
    //  alors il se trouve dans le triangle

    if(sameSide(p,position,p2,p3) && sameSide(p,p2,position,p3) && sameSide(p,p3,position,p2)) return true;

    return false;
}

// Calculer le point du triangle le plus proche à un grain donné

Vector3D Triangle::point_plus_proche(Vector3D const& v) const {

    Plan plan(nullptr,position,normale);

    Vector3D p(plan.point_plus_proche(v));      //  Projection de la position du grain sur le plan dans lequel se trouve le triangle


    if(inTriangle(p)) return p;     //  Si cette projection se trouve dans le triangle, simplement la renvoyer
    else {

        //  Sinon: vérifier de quel côté du triangle se trouve la projecton p
        //         vérifier si p se trouve entre deux sommets --> le projeter sur le côté entre les deux sommets
        //         sinon renvoyer le sommet le plus proche

        if(!sameSide(position,p,p2,p3)) {
            if(!sameSide(p2,p,position,p3)) return p3;
            if(!sameSide(p3,p,position,p2)) return p2;
            //projeter p sur p2-p3
            Triangle t(nullptr,p2,p,p3);
            return p-t.hauteur();

        }
        else if(!sameSide(p2,p,position,p3)) {
            if(!sameSide(p3,p,position,p2)) return position;
            //projeter p sur pos-p3
            Triangle t(nullptr,position,p,p3);
            return p-t.hauteur();
        }

        else if(!sameSide(p3,p,position,p2)) {
            //projeter p sur pos-p2
            Triangle t(nullptr,p2,p,position);
            return p-t.hauteur();
        }
    }
    return p;
}


//----------PYRAMIDE---------------//

//===========Constructeur============
//  La classe Pyramide ne permet que de créér un type spécifique de pyramide, à savoir une pyramide à 5 faces, i.e. une base rectangulaire et 4 triangles

//  Le constructeur prend par conséquent: Pour la base -> une position, un vecteur normal, une longueur et largeur, et un vectuer unitaire
//  En plus il prend l'hauteur de la pyramide. La classe contient aussi un attribut "sommet", qui est calculé grâce au vecteur normale et l'hauteur

Pyramide::Pyramide(SupportADessin* support, Vector3D const& pos, Vector3D const& normale,
                    double length, double width, Vector3D const& u_length, double height)
    : Obstacle(support,pos), base(Dalle(support,pos,normale,length,width,u_length)), hauteur(height)
{
    sommet = base.centre() + hauteur*normale;
}

//  Calcul du point le plus proche sur la pyramide par rapport à un grain passé en argument

Vector3D Pyramide::point_plus_proche(Vector3D const& v) const {

    std::vector<Obstacle*> faces;       //  Créer un tableau de pointeurs sur le 5 faces (qui sont des obstacles: Dalle et Triangle)

    Dalle* b = new Dalle(base);     //  Déclarer la base comme une dalle

    faces.push_back(b);

    Vector3D p2(position + base.get_largeur()*base.get_larg_unit());
    Vector3D p3(position + base.get_longueur()*base.get_long_unit());
    Vector3D p4(p3 + base.get_largeur()*base.get_larg_unit());

    Triangle* t1 = new Triangle(nullptr,position,p2,sommet);
    Triangle* t2 = new Triangle(nullptr,position,p3,sommet);        //  Déclarer les 4 autres faces comme des triangles
    Triangle* t3 = new Triangle(nullptr,p2,p4,sommet);
    Triangle* t4 = new Triangle(nullptr,p3,p4,sommet);

    faces.push_back(t1); faces.push_back(t2); faces.push_back(t3); faces.push_back(t4);

    double d = distance(b->point_plus_proche(v),v); Vector3D p;

    //  Parcourir le tableau de faces, calculer grâce à la méthode polymorphique le point le plus proche par rapport à chaque face
    //  Stocker la distance minimale, et renvoyer ce point

    for(auto face : faces) {
        if(d > distance(v,face->point_plus_proche(v))) {
            d = distance(v,face->point_plus_proche(v));
            p = face->point_plus_proche(v);
        }
    }

    for(auto face : faces) { delete face; face = nullptr; }

    return p;

}

void Pyramide::move(const double &dt) {
    Obstacle::move(dt);
    base.set_position(position);
    sommet = base.centre() + hauteur * base.get_normale();
}


std::ostream& Pyramide::affiche(std::ostream& out) const {
    out << "Pyramide: [base: " << base << ", hauteur: " << hauteur
        << "]" << std::endl;
    return out;
}

void Pyramide::dessine() {
    if(support != nullptr) return support->dessine(*this);
}
