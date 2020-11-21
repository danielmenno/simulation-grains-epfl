#ifndef GRAINLJUN_H
#define GRAINLJUN_H
#include "grainLJ.h"


class GrainLJun : public GrainLJ
{
public:
    //GrainLJun(SupportADessin*, Vector3D const&, Vector3D const&,
//              Vector3D const&, double const&);
    using GrainLJ::GrainLJ;

    void dessine() override;

    //copie polymorphique

    GrainLJun* clone() const override;

    std::ostream& affiche(std::ostream&) const override;

};

#endif // GRAINLJUN_H


class GrainLJdeux : public GrainLJ {

public:
    using GrainLJ::GrainLJ;

    void dessine() override;

    //copie polymorphique

    GrainLJdeux* clone() const override;

    std::ostream& affiche(std::ostream&) const override;

};


