#ifndef CYLINDRE_H
#define CYLINDRE_H

#include "obstacle.h"



class Cylindre: public Obstacle
{

private:
    double rayon; double hauteur; Vector3D normale;

public:
    Cylindre(SupportADessin*, Vector3D const&, double, double, Vector3D const&);

    Vector3D point_plus_proche(Vector3D const&) const override;

    virtual std::ostream& affiche(std::ostream&) const override;

    virtual void dessine() override;

    Vector3D get_normale() const { return normale; }

    double get_hauteur() const { return hauteur; }

    double get_rayon() const { return rayon; }
};

#endif // CYLINDRE_H
