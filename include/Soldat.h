#ifndef SOLDAT_H
#define SOLDAT_H

#include "Unite.h"

class Soldat : public Unite
{
    public:
        virtual void choixCible() {};
        Soldat(unsigned int prix, unsigned int pv, unsigned int pointAttaque) : Unite(prix, pv, pointAttaque) {};
        virtual ~Soldat();
    protected:

    private:
        unsigned int pm;
};

#endif // SOLDAT_H
