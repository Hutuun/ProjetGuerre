#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>

#include "Unite.h"
#include "Base.h"
#include "Epoque.h"
#include "Prehistoire.h"

class Unite;
//class Prehistoire;

class Joueur
{
    public:
        Joueur(std::string nom, bool dir, unsigned int pos) : m_nom(nom), m_or(0), m_dir(dir), m_epoque(new Prehistoire()),m_pos(pos) {};
        void ajoutUnite(Unite *troupe);
        virtual ~Joueur();
        void changeNom(std::string nom);
        std::string getNom()const;
        bool getDir()const;
        void tour();
        unsigned int getPos()const;
        Unite* acheter();

    protected:

    private:
        std::string m_nom;
        unsigned int m_or;
        bool m_dir;
        std::vector<Unite*> m_troupes;
        Epoque* m_epoque;
        unsigned int m_pos;
};

#endif // JOUEUR_H
