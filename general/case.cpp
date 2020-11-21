#include "case.h"

Case::Case()
{

}

void Case::remove_grain(Grain* g) {
    for(size_t i = 0; i < grains.size(); ++i) {
       if(grains[i] == g) grains.erase(grains.begin() + i);
    }
}


