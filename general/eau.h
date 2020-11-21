#ifndef EAU_H
#define EAU_H
#include "dessinable.h"
#include "supportadessin.h"
#include "dalle.h"



class Eau : public Dessinable
{
private:
    Vector3D position;
    double length; double width; double height;

public:
    Eau(SupportADessin*, Vector3D const&, double = 0.0, double = 0.0, double = 0.0);

    virtual void dessine() override;

    bool inside(Vector3D const&) const;

    std::ostream& affiche(std::ostream&) const;

    Vector3D get_position() const { return position; }
    double get_length() const { return length;}
    double get_width() const { return width; }
    double get_height() const { return height; }
};

std::ostream& operator <<(std::ostream&, Eau const&);

#endif // EAU_H
