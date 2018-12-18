#ifndef BATIMENT_H
#define BATIMENT_H

#include "Unite.h"


class Batiment : public Unite
{
    public:
        Batiment(unsigned int prix, unsigned int pv, unsigned int pointAttaque):Unite(prix, pv, pointAttaque) {};
        virtual ~Batiment();
        virtual void choixCible() {};
    protected:

    private:
};

#endif // BATIMENT_H
