#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <iostream>
#include <string>

#include "Unite.h"
#include "Base.h"
#include "Epoque.h"
#include "Prehistoire.h"
#include "Autre.h"

class Unite;

class Joueur
{
    public:
        Joueur(std::string nom, unsigned int pos) : m_or(0), m_epoque(new Prehistoire()), m_nom(nom), m_pos(pos), m_base(nullptr) {};
        void ajoutUnite(Soldat *troupe);
        void ajoutBatiment(Batiment *batiment);
        void ajoutBase(Base* base);
        virtual ~Joueur();
        void changeNom(std::string nom);
        std::string getNom()const;
        bool getDir()const;
        virtual void tour();
        unsigned int getPos()const;
        Soldat* acheter();
        bool estVivant();
        void ajoutOr(unsigned int argent);
        void affiche()const;
        Base* getBase();
        void tue(Soldat*mort);
        void tue(Batiment*mort);
        virtual void tourJoueur();
        std::string sauvegarde();
        virtual bool isIA();

    protected:
        unsigned int m_or;
        Epoque* m_epoque;
        std::string m_nom;
        unsigned int m_pos;

    private:
        Base* m_base;
        std::vector<Soldat*> m_troupes;
        std::vector<Batiment*> m_batiments;
};

#endif // JOUEUR_H
