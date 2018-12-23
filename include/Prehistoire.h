#ifndef PREHISTOIRE_H
#define PREHISTOIRE_H

#include "Epoque.h"

class Prehistoire : public Epoque
{
    public:
        Prehistoire();
        virtual ~Prehistoire();
        static int getPrixFantassin();
        static int getPrixArcher();
        static int getPrixCatapulte();

    protected:

    private:
};

#endif // PREHISTOIRE_H
