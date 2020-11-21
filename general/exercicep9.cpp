#include <iostream>
#include <cmath>
#include <vector>
#include "vector3d.h"
#include "systeme.h"

#include "grainLJsub.h"
#include "plan.h"
//#include "text_viewer.h"

using namespace std;
using namespace physics;

int main() {



    GrainLJun un1(nullptr, Vector3D (0,0,0), Vector3D (0,0,0), Vector3D (0,0,0), 0.4);
    GrainLJun un2(nullptr, Vector3D (0,0,0), Vector3D (1,0,0), Vector3D (0,0,0), 0.4);
    GrainLJun un3(nullptr, Vector3D (0,0,0), Vector3D (0.5, sqrt(3)/2, 0), Vector3D (0,0,0), 0.4);
    GrainLJdeux deux1(nullptr,  Vector3D (0,0,0), Vector3D (0.5, sqrt(3)/6, sqrt(6)/3), Vector3D (0,0,0), 0.4);

    Plan obstacle(nullptr, Vector3D (0,0,-0.9), Vector3D (0,0,1));

    vector<Grain*> sand;
    vector<Obstacle*> obstacles;
    vector<Source*> sources = {};

    sand.push_back(&un1);
    sand.push_back(&un2);
    sand.push_back(&un3);
    sand.push_back(&deux1);

    obstacles.push_back(&obstacle);

    //TextViewer text(cout);


    Systeme test(nullptr,sand, sources, obstacles);

    double dt = 0.001;

    for(double x(0.00); x <= 0.1; x += 0.001) {
        cout << "Etat du systeme au temps " << x << endl;
        //test.affiche_grains(cout);

        test.dessine();

        test.evolue(dt);
        cout << endl;
    }

    return 0;
}
