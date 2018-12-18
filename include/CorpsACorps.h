#ifndef CORPSACORPS_H
#define CORPSACORPS_H

#include "Soldat.h"


class CorpsACorps : public Soldat
{
    public:
        CorpsACorps(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm) : Soldat(prix, pv, pointAttaque,pm) {};
        virtual ~CorpsACorps();
        void choixCible() {};
    protected:

    private:
};

#endif // CORPSACORPS_H
