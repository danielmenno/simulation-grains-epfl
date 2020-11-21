#include <iostream>
#include <cmath> //Pour les puissances (pow(x,y)), qui sont dans les grains
#include "vector3D.h"
#include "grain.h"
#include "plan.h"
#include "dalle.h"


using namespace std;


int main() {

    Vector3D v1(1,2,-0.1); Vector3D v2(2.6,3.5,4.1); Vector3D v3 = v1;
    Vector3D v;

    cout << "Sum: "<< (v1 + v2) << endl;
    cout << "Sum with nulvector: " << (v1 + v) << endl;
    cout << "Difference: " << (v1-v2) << endl;
    cout << "Difference with itself: " << (v1-v1) << endl;
    cout << "Opposite: " << -v1 << endl;
    cout << "Sum with opposite: " << (-v2 + v1) << endl;
    cout << "Multiply with scalar: " << 3 * v1 << endl;
    cout << "Dot product: " << (v1 * v2) << endl;
    cout << "Cross product: " << (v1 ^ v2) << endl;
    cout << "Norm squared: " << v1.norme2() << endl;


    return 0;

}
