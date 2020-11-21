#ifndef SUPPORTADESSIN_H
#define SUPPORTADESSIN_H


//Classes dessinables

class GrainLJun; class GrainLJdeux; class Systeme; class Plan; class Dalle; class Sphere; class Triangle; class Pyramide;
class Cylindre; class Brique; class Eau; class Source;

class SupportADessin
{
public:
    SupportADessin();

    virtual ~SupportADessin() {}

    virtual void dessine(GrainLJun const&) = 0;
    virtual void dessine(GrainLJdeux const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Plan const&) = 0;
    virtual void dessine(Dalle const&) = 0;
    virtual void dessine(Sphere const&) = 0;
    virtual void dessine(Pyramide const&) = 0;
    virtual void dessine(Triangle const&) = 0;
    virtual void dessine(Cylindre const&) = 0;
    virtual void dessine(Brique const&) = 0;
    virtual void dessine(Eau const&) = 0;
    virtual void dessine(Source const&) = 0;


};

#endif // SUPPORTADESSIN_H
