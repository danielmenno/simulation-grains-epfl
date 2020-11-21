#ifndef SOURCE_H
#define SOURCE_H
#include <vector>

#include "grainLJ.h"
#include "aleatoire.h"
#include <iostream>


class Source : public Dessinable
{
private:    
    Vector3D x; //position de la source
    Vector3D v_init; //vitesse initiale moyenne a la sortie de la source
    double sigma_v; //ecart-type des vitesses
    double sigma_r; //ecart-type des rayons
    double debit; //nbe de grains par unité de temps
    Grain* ref; //pointeur sur ref à copier
    bool etat; //source ouverte ou fermée

public:
// Constructeurs/destructeurs =======================
    Source(SupportADessin*, Vector3D const&, Vector3D const&, double const&,
           double const&, double const&, Grain* const&,
           const bool & = false);

    Source(Source const&) = delete; //Supprime constructeur de copie, c'est stylé ahah

    Source(Source const&, Vector3D const&);

    ~Source(); // delete le pointeur vers la reference

//Accesseurs ===================
    Vector3D get_position() const { return x; }
    double get_debit() const {return debit;}
    bool get_etat() const { return etat;}
//Manipulateurs ==================

// Source =============================
    void off(); // source ouverte
    void on(); // source fermée
// Dessin ===========================
    virtual void dessine() override;

//Méthode(s) ========================
    void creation(std::vector<Grain*>&, double);
//Affichage==========================
    std::ostream& affiche(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, Source const&);

#endif // SOURCE_H
