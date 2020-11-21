#ifndef SPHERE_H
#define SPHERE_H

#include "obstacle.h"


class Sphere: public Obstacle
{

private:
    double rayon;

public:
    Sphere(SupportADessin*, Vector3D const& pos, double const& rad);
    Vector3D point_plus_proche(Vector3D const&) const override;

    double get_r() const { return rayon; }

    void dessine() override;

    std::ostream& affiche(std::ostream& out) const override;

};

#endif // SPHERE_H
