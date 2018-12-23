#ifndef PREHISTOIRE_H
#define PREHISTOIRE_H

#include "Epoque.h"

class Prehistoire : public Epoque
{
    public:
        Prehistoire();
        virtual ~Prehistoire();
        int getPrixFantassin();
        int getPrixArcher();
        int getPrixCatapulte();

    protected:

    private:
};

#endif // PREHISTOIRE_H
