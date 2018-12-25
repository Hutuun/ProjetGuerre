#ifndef CORPSACORPS_H
#define CORPSACORPS_H

#include "Soldat.h"

class CorpsACorps : public Soldat
{
    public:
        CorpsACorps(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, std::string dir,unsigned int pos) : Soldat(prix, pv, pointAttaque,pm, dir,pos) {};
        virtual ~CorpsACorps();
        int choixCible();
        virtual void affiche()const {};
        virtual int tour() {return 0;};
    protected:

    private:
};

#endif // CORPSACORPS_H
