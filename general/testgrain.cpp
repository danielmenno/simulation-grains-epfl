#include "grainLJsub.h"
#include "vector3d.h"

using namespace std;

int main() {

    Vector3D vitesse(1, 1, 1);
    Vector3D position(0, 0, 0);
    Vector3D origine(0, 0, 0);

    GrainLJun test(nullptr, vitesse, position, origine, 3);

    cout << test.masse() << endl; //masse theorique 113.blabla

    cout << test << endl;

    GrainLJun test2(test);

    cout << test2 << endl;

    test2.move(1);

    cout << test2 << endl;

    test.dessine();


return 0;
}
