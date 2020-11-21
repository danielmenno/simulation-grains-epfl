#include "source.h"
#include "grain.h"
#include <iostream>
#include "vector3d.h"
#include <vector>

using namespace std;

int main() {
    Vector3D position(0,0,0);
    Vector3D v_init(0.5, 2, 3);
    Grain reference(position, Vector3D (1, 2, 1), Vector3D (0,0,0), 3);

    Source test(position, v_init, 0, 0, 4, reference, false);
    Source test2(test, v_init);

    vector<Grain*> tableau_test = {};
    Source test3(v_init, position, 0.5, 1.5, 5, reference, true);

    test.creation(tableau_test, 10);
    test2.creation(tableau_test, 4);
    test3.creation(tableau_test, 1000);

    for(auto e : tableau_test) {
        cout << (*e) << endl;
    }

return 0;
}
