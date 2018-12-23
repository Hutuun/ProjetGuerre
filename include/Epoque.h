#ifndef EPOQUE_H
#define EPOQUE_H

#include "Fantassin.h"
#include "Archer.h"
#include "Catapulte.h"

class Epoque
{
    public:
        Epoque(std::string nom) : m_nom(nom) {};
        virtual ~Epoque();
        virtual Fantassin* getFantassin() {return nullptr;};
        virtual Archer* getArcher() {return nullptr;};
        virtual Catapulte* getCatapulte() {return nullptr;};

    protected:

    private:
        std::string m_nom;
};

#endif // EPOQUE_H
