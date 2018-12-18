#ifndef BATIMENT_H
#define BATIMENT_H

#include "Unite.h"


class Batiment : public Unite
{
    public:
        Batiment();
        virtual ~Batiment();
        virtual void choixCible() {};
    protected:

    private:
};

#endif // BATIMENT_H
