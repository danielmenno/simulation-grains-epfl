#include "grainLJsub.h"

using namespace std;

//========Copies polymorphiques des grains==========
GrainLJun* GrainLJun::clone() const {
    return new GrainLJun(*this);
}

GrainLJdeux* GrainLJdeux::clone() const {
    return new GrainLJdeux(*this);
}

//==============================================
std::ostream& GrainLJun::affiche(std::ostream& out) const {
    out << "Grain de type 1 : ";
    GrainLJ::affiche(out);
    return out;
}

std::ostream& GrainLJdeux::affiche(std::ostream& out) const {
    out << "Grain de type 2 : ";
    GrainLJ::affiche(out);
    return out;
}

void GrainLJun::dessine() {
    if(support != nullptr) support->dessine(*this);
}

void GrainLJdeux::dessine() {
    if(support != nullptr) support->dessine(*this);
}

