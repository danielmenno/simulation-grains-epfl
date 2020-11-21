#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "vector3d.h"
#include "dessinable.h"
#include "supportadessin.h"


class Obstacle: public Dessinable
{

protected:
    Vector3D position; Vector3D vitesse; bool mouvement;           //Position de l'obstacle: attribut commun à tous les obstacles,
                                                        // qu'importe la forme

public:

    Obstacle(SupportADessin*, Vector3D const& = {0,0,0}, Vector3D const& = {0,0,0}, bool = true);

    Vector3D get_position() const { return position; }

    virtual Vector3D point_plus_proche(Vector3D const&) const = 0;

    virtual std::ostream& affiche(std::ostream&) const = 0;

    virtual void move(double const&);
    //======================================================
    void set_vitesse(const Vector3D &v) { vitesse = v; }

    Vector3D get_vitesse() const { return vitesse; }

    bool get_mouvement() const { return mouvement; }

    void set_mouvement(bool b) { mouvement = b; }

    //======================================================
    virtual ~Obstacle() {}

};

std::ostream& operator<<(std::ostream&, Obstacle const&);

#endif // OBJETS_H
