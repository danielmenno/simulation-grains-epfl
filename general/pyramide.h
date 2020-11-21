#ifndef PYRAMIDE_H
#define PYRAMIDE_H
#include "dalle.h"

class Triangle: public Obstacle {

protected:
    Vector3D p2; Vector3D p3; Vector3D normale;

public:
    Triangle(SupportADessin*, Vector3D const&, Vector3D const&, Vector3D const&);

    Triangle(SupportADessin* sup) : Obstacle(sup) {}

    Vector3D get_p2() const { return p2; }
    Vector3D get_p3() const { return p3; }

    Vector3D point_plus_proche(Vector3D const&) const override; // à definir

    Vector3D hauteur() const;

    void dessine() override;
    std::ostream& affiche(std::ostream&) const override;

    bool inTriangle(Vector3D const&) const;

    Vector3D get_norm() const { return normale; }

};


bool sameSide(Vector3D const&, Vector3D const&, Vector3D const&, Vector3D const&);

class Pyramide : public Obstacle
{
private:
    Dalle base; double hauteur; Vector3D sommet;

public:
    Pyramide(SupportADessin*, Vector3D const&, Vector3D const&, double, double, Vector3D const&, double);

    Dalle get_base() const { return base; }

    virtual void move(double const&) override;

    Vector3D point_plus_proche(Vector3D const&) const override;

    std::ostream& affiche(std::ostream&) const override;

    void dessine() override;

    Vector3D get_sommet() const { return sommet; }

};

#endif // PYRAMIDE_H
