#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "CorpsACorps.h"

class Fantassin : public CorpsACorps
{
    public:
        Fantassin(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, std::string dir,unsigned int pos) : CorpsACorps(prix, pv, pointAttaque,pm, dir,pos) {};;
        virtual ~Fantassin();
        void affiche()const;
        void tour();

    protected:

    private:
};

#endif // FANTASSIN_H
