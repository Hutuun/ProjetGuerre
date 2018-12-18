#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "../../include/Case.h"

class Terrain
{
    public:
        static Terrain& getInstanTerrain();

        virtual ~Terrain();

    protected:

    private:
        static Terrain m_instance;
        Terrain(unsigned int taille): m_terrain(taille){};
        std::vector<Case> m_terrain;
};

#endif // TERRAIN_H
