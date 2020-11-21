#include <iostream>
#include "obstacle.h"
#include "plan.h"
#include "dalle.h"
#include "brique.h"
#include "grainLJsub.h"
#include "sphere.h"

using namespace std;

int main() {

    // TEST PLAN - POINT LE PLUS PROCHE

    Vector3D orig1; //origine (0,0,0)
    Vector3D orig2(1,2,3);

    Vector3D n1(0,0,2);
    Vector3D n2(0,1,0);
    Vector3D n3(1,0,0);
    Vector3D n4(1,1,1);
    Vector3D n5(1.1,3.3,2.2);
    Vector3D n6(0,0,1);

    Plan plan1(nullptr,orig1, n1);
    Plan plan2(nullptr, orig1, n2);
    Plan plan3(nullptr, orig1, n3);
    Plan plan4(nullptr, orig1, n4);
    Plan plan5(nullptr, orig2, n5);

    Dalle d1(nullptr,orig1,n1,3,4,n6);

   // Dalle* dd1= &d1;

    cout << plan1;

    cout << d1;

    Vector3D p1(0,7,0);
    Vector3D p2(0,0,10);
    Vector3D p3(2,0,0);
    Vector3D p4(5,-4,6);

    cout<<plan2;
    plan2.aff_point_proche(p1);
    plan2.aff_point_proche(p2);

    cout<<plan3;
    plan3.aff_point_proche(p3);

    cout<<plan4;
    plan4.aff_point_proche(p4);

    cout<<plan5;
    plan5.aff_point_proche(p1);


    GrainLJun g1(nullptr,orig1,n2,orig1,3);

    g1.dessine();
    cout<<g1;



    Sphere s(nullptr,orig1, 4);

    cout<<s;



    // TEST BRIQUE - POINT LE PLUS PROCHE  ====== OKAY!!!

    //Brique b1(orig1,3,4,3,n3,n2);

    //cout<< b1.point_plus_proche(p1);



    return 0;
}
