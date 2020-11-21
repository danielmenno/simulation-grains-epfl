#include <iostream>
#include "pyramide.h"
#include "textviewer.h"

using namespace std;

int main() {

    TextViewer* test = new TextViewer(cout);

    Vector3D p1(0,0,0); Vector3D p2(1,0,0); Vector3D p3(0,1,0);

    Vector3D n(0,0,1);

    Vector3D p(-1,1,0);

    Triangle t(test,p1,p2,p3);

    t.dessine();

    Pyramide pyr(test,p1,n,3,4,p2,4);

    pyr.dessine();
    cout << pyr.get_sommet() << endl;
    cout << t.get_norm() << endl;

    cout << t.point_plus_proche(p);

    return 0;
}

