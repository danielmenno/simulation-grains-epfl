#ifndef GRAIN_H
#define GRAIN_H

#include "dessinable.h"
#include "supportadessin.h"
#include "obstacle.h"

#include <cmath>
#include <iostream>


class Grain : public Dessinable {
protected:
    static double rho; // masse volumique
    //double rho = 0;
    Vector3D x; // position
    Vector3D v; // vitesse
    Vector3D f; // somme des forces extérieurs HORS POIDS
    double rayon;
    bool air;
public:
    //Méthode virtuelle
    virtual void dessine() override = 0;

    // Constructeurs - Destructeurs
    Grain(SupportADessin* ,Vector3D const&, Vector3D const&,
          Vector3D const&, double, bool = true);

    virtual ~Grain() {}

    //Copie et méthodes polymorphique
    virtual void add_f(Obstacle*) = 0;
    virtual void add_f(Grain*) = 0;
    virtual void add_f(Vector3D const&) = 0;
    virtual Grain* clone() const = 0;
    virtual std::ostream& affiche(std::ostream&) const = 0;
    //Getters
    double get_r() const { return rayon; }
    Vector3D get_po() const { return x; }
    Vector3D get_v() const { return v; }
    Vector3D get_f() const { return f; }
    void reset_f() { f = 0.0; }
    bool get_milieu() const { return air; }

    //Manipulateur
    void set_vitesse(Vector3D const& tmp) {v = tmp;}
    void set_rayon(double const& r) {rayon = r;}
    void set_position(Vector3D const& tmp) {x = tmp;}
    void set_milieu(bool s) { air = s; }

     // Méthodes
    double masse() const;
    double lambda(); // is cool ->// A revoir! Comment spécifier le milieu?  // Fcontion qui remvoie la valeur de lambda en fct du milieu et de la vitesse
    void add_f();
    void move(double&);
    //Affichage

};


std::ostream& operator<<(std::ostream&, Grain const&);


namespace physics {

Vector3D const g(0,0,-9.81*1000);
double const rho_air(1.3*pow(10,-3));  // Coefficient chelou
double const rho_eau(1);    // Coeficient chelou                   //Voir les complements mathematiques ahah
double const eta_air(1.8*pow(10,-2)); // Coefficient chelou
double const eta_eau(pow(10,-3));    // Coefficient chelou
double const q_air(80*eta_air/(3*rho_air)); // Quotient 80*nu/3*rho ds l'air
double const q_eau(80*eta_eau/(3*rho_eau)); // Quotient 80*nu/3*rho ds l'eau
}

#endif // GRAIN_H
