#include <iostream>
#include "text_viewer.h"
#include "systeme.h"
#include <string>
#include "plan.h"

using namespace std;

int main()
{
TextViewer* ecran(new TextViewer(cout));

Systeme c(ecran);
int nb = 0;
cout<< "Choix de la simulation (1 à 4) : ";
cin >> nb;

try {
    if(nb < 1 || nb > 4) throw string("Simulation non-existente");
    c.initialisation(ecran,nb-1);

    double dt = 0.01;
      for(double x(0.00); x < 1; x += dt) {
          cout << "Etat du systeme au temps " << x << endl;

          c.dessine();

          c.evolue(dt);

          cout << endl;
      }
}
catch (string s) { cerr << s << endl; }
      return 0;

}
