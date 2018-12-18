#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "../../include/Case.h"

using namespace std;

class Terrain
{
    public:
        Terrain(unsigned int taille): m_terrain(taille){};
        virtual ~Terrain();

    protected:

    private:
        vector<Case> m_terrain;
};

#endif // TERRAIN_H
