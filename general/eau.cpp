#include "eau.h"


//Constructeur: 3 possibilités: -juste un position -> niveau d'eau universel à une certaine hauteur en z
//                              -une position et une hauteur -> une "couche" d'eau, i.e. de l'eau sur tout la plan xy avec une profondeur donnée
//                              -position, hauteur, longueur et largeurL -> "bloc" d'eau, par exemple dans une boite ouverte

Eau::Eau(SupportADessin* sup,const Vector3D &pos, double h, double l, double w)
    : Dessinable(sup), position(pos), height(h),length(l), width(w)
{

}

void Eau::dessine() {
    if(support != nullptr) support->dessine(*this);
}

//Méthode qui vérifie si un grain se trouve dans un volume d'eau

bool Eau::inside(Vector3D const &v) const {
    if(length == 0.0 && width == 0.0 && height == 0.0) {    //Cas 1: si niveau universel, simplement verifier si le grain se trouve en-dessous
        if(v.get_z() < position.get_z()) return true;
        return false;
    }

    //Cas 2: Si couche avec profondeur, vérifier si le grain est entre le haut et le bas
    else if(length == 0.0 && width == 0.0) {
        if(v.get_z() < position.get_z() && v.get_z() > (position.get_z() - height))
            return true;
        return false;
    }
    //Cas 3: si cube/brique, vérifier si le grain est à l'interieur de ce volume
    else {
        Dalle d(nullptr,position,{0,0,1},length,width,{1,0,0});     //Surface de l'eau
        Vector3D v0(1,0,0); Vector3D v1(0,1,0);

        if((v0 * (v-d.point_plus_proche(v))) == 0.0 && v1 * (v-d.point_plus_proche(v)) == 0.0) {    //vérifier si la projection et sur le plan
            if(v.get_z() < position.get_z() && v.get_z() > (position.get_z() - height))     //vérifier en z si le grain est entre la surface et le fond
                return true;
        }
        return false;
    }
}

std::ostream& Eau::affiche(std::ostream& out) const {
    out<< "Volume d'eau: [niveau: "<<position.get_z();
    if(height != 0) out << ", profondeur: " << height;
    if(width != 0 && length != 0) out << ",longueur: " << length << ", largeur: " << width;
    out<<"]"<<std::endl;
    return out;
}

std::ostream& operator <<(std::ostream& out, Eau const& w) {
    return w.affiche(out);
}

