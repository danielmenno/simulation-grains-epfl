#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {

        public:

                //CONSTRUCTEUR
            Vector3D(double const& a = 0, double const& b = 0,
            double const& c = 0);

            Vector3D(Vector3D const&);

                //METHODES
                void set_coord(int const&, double const&);

                std::ostream& affiche(std::ostream&) const;

                double get_x() const; double get_y() const; double get_z() const;

                bool compare(Vector3D const&) const;

                Vector3D addition(Vector3D const&);

                Vector3D soustraction(Vector3D const&);

                Vector3D oppose() const;

                Vector3D mult(double const&) const;

                double prod_scal(Vector3D const&) const;

                Vector3D prod_vect(Vector3D const&) const;

                double norme() const; //calcule norme

                double norme2() const; //calcule norme au carre

                Vector3D normalise() const; //renvoye le vecteur normalise (i.e. meme direction mais norme = 1)                        

                //Operators

                Vector3D& operator +=(Vector3D const&);

                Vector3D& operator -=(Vector3D const&);

                double operator *=(Vector3D const&);

                Vector3D& operator ^=(Vector3D const&);

        private:
               double x, y, z;

};

std::ostream& operator<<(std::ostream&, Vector3D const&);

bool operator ==(Vector3D, Vector3D const&);

bool operator !=(Vector3D, Vector3D const&);

const Vector3D operator +(Vector3D, Vector3D const&);

const Vector3D operator -(Vector3D, Vector3D const&);

const Vector3D operator *(double, Vector3D const&);

const Vector3D operator *(Vector3D const&, double);

double operator *(Vector3D, Vector3D const&);

const Vector3D operator ^(Vector3D, Vector3D const&);

const Vector3D operator -(Vector3D);

double distance(Vector3D const&, Vector3D const&);


#endif // VECTOR3D_H
