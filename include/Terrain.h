#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "../../include/Case.h"

class Terrain
{
    public:
        static Terrain* getInstanTerrain();

        virtual ~Terrain();

    protected:

    private:
        static Terrain* terrain;
        Terrain(unsigned int taille): m_terrain(taille){};
        std::vector<Case> m_terrain;
};

#endif // TERRAIN_H
