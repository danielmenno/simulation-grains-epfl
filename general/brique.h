#ifndef BRIQUE_H
#define BRIQUE_H

#include "dalle.h"
#include <vector>

class Brique: public Obstacle
{
private:
    double hauteur; double longueur; double largeur;
    Vector3D haut_unit; Vector3D long_unit; Vector3D larg_unit; // vecteurs unitaires qui donnent les directions
    Vector3D normale;

public:
    Brique(SupportADessin*,Vector3D const&, double, double, double, Vector3D const&, Vector3D const&);  //constructeur , arguments décrits dans le cpp


    Vector3D point_plus_proche(Vector3D const&) const override; //calcule le point plus proche selon cette démarche:
                                                       //calcule le point le plus proche sur chaque face de la brique (6 points du coup)
                                                       //renvoie celui qui est le plus proche des 6
    void dessine() override;

    std::vector<Dalle*> get_faces() const;

    std::ostream& affiche(std::ostream & flot) const override;

};

#endif // BRIQUE_H
