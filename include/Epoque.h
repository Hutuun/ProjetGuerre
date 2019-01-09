#ifndef EPOQUE_H
#define EPOQUE_H

#include "Fantassin.h"
#include "Archer.h"
#include "Catapulte.h"

#include <dirent.h>

class Epoque
{
    public:
        Epoque(std::string nom) : m_nom(nom) {lireFichier();};
        virtual void lireFichier();
        virtual ~Epoque();
        std::string getNom()const;
        virtual Fantassin* getFantassin(std::string nomJoueur, unsigned int pos);
        virtual Archer* getArcher(std::string nomJoueur, unsigned int pos);
        virtual Catapulte* getCatapulte(std::string nomJoueur, unsigned int pos);

    protected:

    private:
        Fantassin *fantassin;
        Archer *archer;
        Catapulte *catapulte;
        std::string m_nom;
};

#endif // EPOQUE_H
