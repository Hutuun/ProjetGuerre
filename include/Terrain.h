#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Case.h"
#include "Base.h"
#include "Joueur.h"

class Terrain
{
    public:
        static Terrain& getInstanTerrain();
        std::vector<Case> getCases()const;
        virtual ~Terrain();
        void affiche()const;
        bool getDir(std::string const nom)const;

    protected:

    private:
        static Terrain m_instance;
        std::vector<Case> m_terrain;
        Joueur j1, j2;
        Terrain(unsigned int taille);
        void ajoutBases();
};

#endif // TERRAIN_H
