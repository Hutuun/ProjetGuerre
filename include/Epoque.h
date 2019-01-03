#ifndef EPOQUE_H
#define EPOQUE_H

#include "SuperSoldat.h"
#include "Archer.h"
#include "Catapulte.h"

class Epoque
{
    public:
        Epoque(std::string nom) : m_nom(nom) {};
        virtual ~Epoque();
        std::string getNom()const;
        virtual SuperSoldat* getFantassin(std::string nomJoueur, unsigned int pos) {return nullptr;};
        virtual Archer* getArcher(std::string nomJoueur, unsigned int pos) {return nullptr;};
        virtual Catapulte* getCatapulte(std::string nomJoueur, unsigned int pos) {return nullptr;};

    protected:

    private:
        std::string m_nom;
};

#endif // EPOQUE_H
