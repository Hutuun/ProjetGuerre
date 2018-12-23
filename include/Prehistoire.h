#ifndef PREHISTOIRE_H
#define PREHISTOIRE_H

#include "Epoque.h"
#include "Fantassin.h"
#include "Archer.h"
#include "Catapulte.h"

class Prehistoire : public Epoque
{
    public:
        Prehistoire();
        virtual ~Prehistoire();
        Fantassin& getFantassin();
        Archer& getArcher();
        Catapulte& getCatapulte();

    protected:

    private:
};

#endif // PREHISTOIRE_H
