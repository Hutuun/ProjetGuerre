#ifndef DISTANCE_H
#define DISTANCE_H

#include "Soldat.h"


class Distance : public Soldat
{
    public:
        Distance(unsigned int prix, unsigned int pv, unsigned int pointAttaque) : Soldat(prix,pv,pointAttaque) {};
        virtual ~Distance();
        virtual void choixCible() {};
    protected:

    private:
        int portee;
};

#endif // DISTANCE_H
