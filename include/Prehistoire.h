#ifndef PREHISTOIRE_H
#define PREHISTOIRE_H

#include "Epoque.h"
#include "Fantassin.h"
#include "Archer.h"
#include "Catapulte.h"

class Prehistoire : public Epoque
{
    public:
        Prehistoire() : Epoque("Prehistoire") {};
        virtual ~Prehistoire();
        Fantassin* getFantassin(std::string nomJoueur, unsigned int pos);
        Archer* getArcher(std::string nomJoueur, unsigned int pos);
        Catapulte* getCatapulte(std::string nomJoueur, unsigned int pos);

    protected:

    private:
};

#endif // PREHISTOIRE_H
