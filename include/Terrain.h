#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Case.h"
#include "Base.h"

class Terrain
{
    public:
        static Terrain& getInstanTerrain();
        std::vector<Case> getCases()const;
        virtual ~Terrain();
        void affiche()const;
        void ajoutBases();

    protected:

    private:
        static Terrain m_instance;
        Terrain(unsigned int taille): m_terrain(taille){};
        std::vector<Case> m_terrain;
};

#endif // TERRAIN_H
