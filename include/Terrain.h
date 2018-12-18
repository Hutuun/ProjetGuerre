#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "../../include/Case.h"

using namespace std;

class Terrain
{
    public:
        Terrain();
        virtual ~Terrain();

    protected:

    private:
        vector<Case> terrain;
};

#endif // TERRAIN_H
