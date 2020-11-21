#ifndef DESSINABLE_H
#define DESSINABLE_H


class SupportADessin;

class Dessinable
{

protected:
    SupportADessin* support;

public:
    Dessinable(SupportADessin* = nullptr);

    virtual ~Dessinable() {}   //destructeur

    virtual void dessine() = 0;
};

#endif // DESSINABLE_H
