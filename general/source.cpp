#include "aleatoire.h"
#include "source.h"
#include "grain.h"
#include <vector>
#include <iostream>

// Constructeurs/Destructeurs =======================
Source::Source(SupportADessin* support, Vector3D const& po, Vector3D const& v, double const& sv,
               double const& sr, double const& debit, Grain* const& ref,
               bool const& etat)
    : Dessinable(support), x(po), v_init(v), sigma_v(sv), sigma_r(sr), debit(debit),
      ref(ref->clone()), etat(etat) {}
Source::~Source() {delete ref; ref = nullptr;}

Source::Source(Source const& copy, Vector3D const& position)
    : Source(copy.support, position, copy.v_init, copy.sigma_v, copy.sigma_r, copy.debit,
             (copy.ref)->clone(), copy.etat) {}

// Source =============================
void Source::off() {etat = false;}
void Source::on() {etat = true;}

// Dessin ==========================
void Source::dessine() {
    if(support != nullptr) support->dessine(*this);
}

//Méthode(s) ========================
void Source::creation(std::vector<Grain*>& tab, double  dt) {
    if(etat) {
        Aleatoire generator;

        double fraction(debit*dt); // fraction = debit "vrai", mais a priori non entier
        unsigned int nombre(fraction);      // partie entière
        fraction -= nombre;             // partie fractionnaire

        // on ajoute 1 au hasard, proportionnellement à la partie fractionnaire :
        if ( generator.uniforme(0.0, 1.0) < fraction ) ++nombre;
        for(size_t i(0); i < nombre; ++i) {
            Grain* tmp(ref->clone());
            tmp->set_vitesse(Vector3D(generator.gaussienne(v_init.get_x(), sigma_v),
                                 generator.gaussienne(v_init.get_y(), sigma_v),
                                 generator.gaussienne(v_init.get_z(), sigma_v)));
            double r_tmp(generator.gaussienne(ref->get_r(), sigma_r));
            if(r_tmp < 0) r_tmp = -r_tmp;
            if(r_tmp < pow(10, -2)) r_tmp = ref->get_r();
            tmp->set_rayon(r_tmp);
            tmp->set_position(x);
            tmp->move(dt);
            tab.push_back(tmp);

        }
    }
}

//Affichage=====================
std::ostream& Source::affiche(std::ostream& out) const {
    out << " Une source : [position : " << x << ", debit : " << debit << "]" << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream& out, Source const& source) {
    return source.affiche(out);
}
