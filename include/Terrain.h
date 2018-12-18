#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "../../include/Case.h"

class Terrain
{
    public:
        Terrain(unsigned int taille): m_terrain(taille){};

        std::vector<Case> getTerrain()const;

        virtual ~Terrain();

    protected:

    private:
        std::vector<Case> m_terrain;
};

#endif // TERRAIN_H
