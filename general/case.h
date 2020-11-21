#ifndef CASE_H
#define CASE_H
#include "grain.h"
#include <vector>

class Case
{

private:
    std::vector<Grain*> grains;

public:
    Case();

    //void ajoute_grain(Grain);

    int nb_grains() const { return grains.size(); }

    std::vector<Grain*> get_grains() const { return grains; }

    void ajoute_grain(Grain* g) { grains.push_back(g); }
    void remove_grain(Grain* g); //{ grains.erase(grains.begin()+i); }

    ~Case() {}
};

#endif // CASE_H
