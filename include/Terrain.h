#ifndef TERRAIN_H
#define TERRAIN_H

#define TAILLE 12
#define MAX TAILLE-2
#define MIN 1

#include <vector>
#include <dirent.h>
#include <fstream>

#include "Case.h"
#include "Base.h"
#include "IA.h"

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
        void ajoutOccupant(Batiment* const occupant,unsigned int pos);
        bool fini();
        void tue(Soldat* mort);
        void tue(Batiment* mort);
        void sauvegarde();
        void chargement();

    protected:

    private:
        void initJoueur(Joueur** j, unsigned int pos);
        static Terrain* m_instance;
        std::vector<Case*> m_terrain;
        Joueur* j1;
        Joueur* j2;
        Terrain();
        void ajoutBases();
};

#endif // TERRAIN_H
