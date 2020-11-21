#ifndef DALLE_H
#define DALLE_H
#include "plan.h"

//CETTE CLASSE PERMET DE CREER UNE PORTION SPECIFIQUE D'UN PLAN INFINI


class Dalle: public Plan               //heritage
{
private:
    double longueur; double largeur;
    Vector3D long_unit; Vector3D larg_unit;
    Vector3D vitesse = {0,50,0};

public:

    //CONSTRUCTEUR
    Dalle(SupportADessin*, Vector3D const&, Vector3D const&, double, double, Vector3D const&);


    //Getters
    Vector3D get_long_unit() const { return long_unit; }
    Vector3D get_larg_unit() const { return larg_unit; }
    double get_longueur() const { return longueur; }
    double get_largeur() const { return largeur; }
    void set_position(Vector3D const& p) { position = p; }
    Vector3D point_plus_proche(const Vector3D &) const override;     //specialisation de la methode pour trouver le point sur
                                                            //la portion du plan de dimension finie
    std::ostream& affiche(std::ostream&) const override;

    Vector3D centre() const;

    void aff_point_proche(Vector3D const&);

    void dessine() override;

    //void move(double const&) override;

};



#endif // DALLE_H
