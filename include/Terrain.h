#ifndef TERRAIN_H
#define TERRAIN_H

#define MAX 11
#define MIN 2
#define TAILLE 14

#include <vector>
#include "Case.h"
#include "Base.h"
#include "Joueur.h"

class Terrain
{
    public:
        static Terrain* getInstanTerrain();
        std::vector<Case*> getCases();
        virtual ~Terrain();
        void affiche()const;
        bool getDir(std::string const nom)const;
        void tour();
        void ajoutOccupant(Soldat* const occupant,unsigned int pos);
        bool fini();

    protected:

    private:
        static Terrain* m_instance;
        std::vector<Case*> m_terrain;
        Joueur j1, j2;
        Terrain(unsigned int taille);
        void ajoutBases();
};

#endif // TERRAIN_H
