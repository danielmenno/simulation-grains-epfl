#include <iostream>
#include <cmath> // Pour la norme #gezellig
#include "vector3d.h"


using namespace std;

//Constructeur

Vector3D::Vector3D(double const& a, double const& b, double const& c) //par défaut = vecteur nul (0,0,0)
    : x(a), y(b), z(c)
{}

Vector3D::Vector3D(Vector3D const& vect)                    //Constructeur de copie
    : x(vect.x), y(vect.y), z(vect.z)
{}

void Vector3D::set_coord(int const& coord, double const& value) {

    switch (coord) {
        case 0: x = value;
            break;
        case 1: y = value;
            break;
        case 2: z = value;
            break;
    }
}
//=========Getters========
double Vector3D::get_x() const { return x; }
double Vector3D::get_y() const { return y; }
double Vector3D::get_z() const { return z; }

//=============================

ostream& Vector3D::affiche(ostream& out) const {
    out<<"("<<x<<", "<<y<<", "<<z<<")";
    return out;
}

bool Vector3D::compare(Vector3D const& vect) const {            //compare deux vecteurs -utilise pour l'operateur ==
    if(vect.x == x) {
        if(vect.y == y) {
            if(vect.z == z) {
               return true;
            }
        }
    }
    return false;
}

Vector3D Vector3D::addition(Vector3D const& vect) {         //inutile
    Vector3D v(x + vect.x,y + vect.y,z + vect.z);
    return v;
}

Vector3D Vector3D::soustraction(Vector3D const& vect) {     //inutile
    Vector3D v(x - vect.x,y - vect.y,z - vect.z);
    return v;
}

Vector3D Vector3D::oppose() const {        // pour l'operateur -
    Vector3D v(-x, -y, -z);
    return v;
}

Vector3D Vector3D::mult(double const& c) const {           //utilisé pour surcharge
    Vector3D v(c*x, c*y, c*z);
    return v;
}

double Vector3D::prod_scal(Vector3D const& v) const {       //inutile
    return x*v.x + y*v.y+ z*v.z;
}

Vector3D Vector3D::prod_vect(Vector3D const& v) const {         //inutile
    Vector3D p(y*v.get_z()-z*v.get_y(),
    z*v.get_x()-x*v.get_z(),
    x*v.get_y()-y*v.get_x());
    return p;
}

double Vector3D::norme() const {           //calcule la norme du vecteur
    return sqrt(x*x + y*y + z*z);
}

double Vector3D::norme2() const{            //calcule la norme du vecteur au carré
    return x*x + y*y + z*z;
}

Vector3D Vector3D::normalise() const {          //normalise le vecteur sous condition que ce ne soit pas le vecteur nul
    if(norme() != 0)  {
        Vector3D v(x/norme(),y/norme(),z/norme());
        return v;
    }
    return *this;
}


//============operators====================

ostream& operator <<(ostream& out, Vector3D const& v) { //affichage
    v.affiche(out);
    return out;
}

Vector3D& Vector3D::operator +=(Vector3D const& v) {     // somme interne
   x += v.x; y += v.y; z += v.z;
   return *this;
}

const Vector3D operator +(Vector3D vect1, Vector3D const& vect2) {   //somme externe
    return vect1+=vect2;
}

Vector3D& Vector3D::operator -=(Vector3D const& v) {             // difference interne
    x -= v.x; y -= v.y; z -= v.z;
    return *this;
}

const Vector3D operator -(Vector3D vect1, Vector3D const& vect2) {       //difference externe
    return vect1-=vect2;
}

bool operator ==(Vector3D vect1, Vector3D const& vect2) {       //egalite
    return vect1.compare(vect2);
}

bool operator !=(Vector3D vect1, Vector3D const& vect2) {       // non-egalite
    return (!(vect1 == vect2));
}

const Vector3D operator *(double k, Vector3D const& vect) {           //multiplication par scalaire (gauche)
    return vect.mult(k);
}

const Vector3D operator *(Vector3D const& vect, double k) {         // idem qu'au dessus mais à droite
    return (k*vect);
}

double Vector3D::operator *=(Vector3D const& v){            //produit scalaire interne
    return x*v.x + y*v.y + z*v.z;
}

double operator *(Vector3D vect1, Vector3D const& vect2) {  //produit scalaire externe
    return vect1 *= vect2;
}

Vector3D& Vector3D::operator ^=(Vector3D const& v) {     //produit vectoriel interne

    double x_temp = x; double y_temp = y;

    x = y*v.z-z*v.y;
    y = z*v.x-x_temp*v.z;
    z = x_temp*v.y-y_temp*v.x;
    return *this;
}

const Vector3D operator ^(Vector3D v1, Vector3D const& v2) {      //produit vectoriel externe
    return v1^=v2;
}

const Vector3D operator -(Vector3D v1) {  // opposé du vecteur
    return v1.oppose();
}

double distance(Vector3D const& v1, Vector3D const& v2) {       //calcule la distance entre deux points donnés
    return (v1-v2).norme();
}
