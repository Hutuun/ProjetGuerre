#ifndef CORPSACORPS_H
#define CORPSACORPS_H

#include "Soldat.h"

class CorpsACorps : public Soldat
{
    public:
        CorpsACorps(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, std::string dir) : Soldat(prix, pv, pointAttaque,pm, dir) {};
        virtual ~CorpsACorps();
        void choixCible(unsigned int pos);
        virtual void affiche()const {};
    protected:

    private:
};

#endif // CORPSACORPS_H
