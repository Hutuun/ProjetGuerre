#ifndef TERRAIN_H
#define TERRAIN_H

#define TAILLE 50
#define MAX (TAILLE-2)
#define MIN 1
#define TOURMAX 200

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
        static Terrain* getInstanTerrain(bool *chgAge,std::string *adresse);
        void init();
        void ajoutBases(Joueur *j,Base *base);

    protected:

    private:
        Epoque* chargeEpoque(std::string epoque);
        Soldat* chargeUnite(std::string unite, std::string dir, unsigned int pv, unsigned int pm, unsigned int porte, unsigned int pos, unsigned int prix, unsigned int pa);
        Batiment* chargeBatiment(std::string batiment, std::string dir, unsigned int pv, unsigned int pos, unsigned int prix, unsigned int pa);
        void initJoueur(Joueur** j, unsigned int pos);
        static Terrain* m_instance;
        std::vector<Case*> m_terrain;
        Joueur* j1;
        Joueur* j2;
        Terrain();
        void ajoutBases();
        static bool *m_chgAge;
        static std::string *m_adresse;
        unsigned int nbTour=0;
};

#endif // TERRAIN_H
