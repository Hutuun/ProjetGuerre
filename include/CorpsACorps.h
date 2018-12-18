#ifndef CORPSACORPS_H
#define CORPSACORPS_H

#include "Soldat.h"


class CorpsACorps : public Soldat
{
    public:
        CorpsACorps(unsigned int prix, unsigned int pv, unsigned int pointAttaque) : Soldat(prix, pv, pointAttaque) {};
        virtual ~CorpsACorps();
        void choixCible() {};
    protected:

    private:

};

#endif // CORPSACORPS_H
