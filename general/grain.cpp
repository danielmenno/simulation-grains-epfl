#include "grain.h"
#include "vector3d.h"


using namespace std;
using namespace physics;

double Grain::rho = 0.9;

// Accesseurs et manipulateurs sont dans le .h, ne pas oublier
// CLASSES VIRTUELLE PURE, CF LE .H


//========Constructeur: un grain est construit à partir de sa vitesse, sa position, l'ensemble des forces qui s'appliquent dessus,
//                      son rayon et le milieu dans lequel il se trouve

Grain::Grain(SupportADessin* vue,Vector3D const& v, Vector3D const& p,
             Vector3D const& f, double rad, bool air_)
    :  Dessinable(vue), x(p), v(v), f(f), rayon(rad), air(air_)
{}

//dessine virtuelle pure

double Grain::masse() const { return rho*4*M_PI*pow(get_r(),3)/3; }

//Coefficient de frottement fluide: calculé grâce au complément math. en fonction du volume dans lequel se trouve le grain

double Grain::lambda() {
    if(air) {
        if(v.norme() <= q_air/get_r()) {return (6*M_PI*get_r()*eta_air);}
        else { return (rho_air*v.norme()*pow(get_r(),2)*9*M_PI/40);}
    }
    else {
        if(v.norme() <= q_eau/get_r())  {return (6*M_PI*get_r()*eta_eau);}
        else { return (rho_eau*v.norme()*pow(get_r(),2)*9*M_PI/40);}
    }
}

//Calcul de la force "perso" ajoutée

void Grain::add_f() {
    f += (masse()*g) - (lambda()*v);
    if(air) f -= rho_air*(4*M_PI*pow(rayon,3)/3)*g;
    else {                                              //Poussée d'Archimède selon le milieu (air ou eau)
        f -= rho_eau*(4*M_PI*pow(rayon,3)/3)*g;
    }
}

//Faire bouger le grain pendant un temps dt passé en paramètre selon les lois de Newton

void Grain::move(double& dt) {
    v += (((dt)/masse())*get_f());
    x += (dt*v);
    reset_f();          //Remettre la force sur le grain à 0 pour la prochaine évolution
}

ostream& operator<<(ostream& out, Grain const& sand) {
    return sand.affiche(out);
}
