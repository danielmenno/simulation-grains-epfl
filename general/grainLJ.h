#ifndef GRAINLJ_H
#define GRAINLJ_H

#include "grain.h"

class GrainLJ : public Grain
{
private:
    static double epsilon; //constante pour les forces
    static double sigma;//de même (namespace ou non?)
    double forceLJ_function(double const&) const;
    void adjust_position(Vector3D const&, double const& = 0);
public:

    using Grain::Grain;     //  On utilise le constructeur de Grain car GrainLJ contient les mêmes attributs

    Vector3D forceLJ(Vector3D const&) const; //retourne les valeurs des forces enbtres les grains
    void add_f(Obstacle* ) override;
    void add_f(Grain* ) override;
    void add_f(Vector3D const&) override;
    std::ostream& affiche(std::ostream&) const override;

};

#endif // GRAINLJ_H
