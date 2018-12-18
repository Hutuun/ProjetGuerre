#ifndef SOLDAT_H
#define SOLDAT_H

#include "Unite.h"

class Soldat : public Unite
{
    public:
        virtual void choixCible() {};
        Soldat();
        virtual ~Soldat();
    protected:

    private:
        unsigned int pm;
};

#endif // SOLDAT_H
