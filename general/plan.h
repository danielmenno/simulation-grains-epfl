#ifndef PLAN_H
#define PLAN_H

#include "obstacle.h"
#include "grain.h"

class Plan: public Obstacle
{
protected:
    Vector3D normale;

public:
    Plan(SupportADessin*, Vector3D const&, Vector3D const&);

    Vector3D get_pos() const { return position; }
    Vector3D get_normale() const { return normale; }

    Vector3D point_plus_proche(Vector3D const&) const override;  //calcule le point sur le plan le plus proche d'un grain
                                                       // à une position donnée

    Vector3D distance(Vector3D const&) const;     // calcule la distance la plus courte entre le plan et un grain

    void dessine() override;

    void aff_point_proche(Vector3D const&) const;

    std::ostream& affiche(std::ostream&) const override;
};

#endif // PLAN_H
