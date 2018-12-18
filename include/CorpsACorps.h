#ifndef CORPSACORPS_H
#define CORPSACORPS_H

#include "Soldat.h"
#include "Terrain.h"

class CorpsACorps : public Soldat
{
    public:
        CorpsACorps(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, bool dir) : Soldat(prix, pv, pointAttaque,pm, dir) {};
        virtual ~CorpsACorps();
        void choixCible(unsigned int pos);
    protected:

    private:
};

#endif // CORPSACORPS_H
