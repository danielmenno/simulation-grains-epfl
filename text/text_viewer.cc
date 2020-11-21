#include <iostream> // pour endl
#include "text_viewer.h"
#include "systeme.h"

using namespace std;

void TextViewer::dessine(const Systeme &a_dessiner)
{
  flot << a_dessiner << std::endl;
}

void TextViewer::dessine(const Dalle & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Plan & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Sphere & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Triangle & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Pyramide & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const GrainLJun & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const GrainLJdeux & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Cylindre & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Brique & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Eau & a_dessiner) {
    flot << a_dessiner << endl;
}

void TextViewer::dessine(const Source & a_dessiner) {
    flot << a_dessiner << endl;
}
