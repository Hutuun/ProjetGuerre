#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "CorpsACorps.h"

class Fantassin : public CorpsACorps
{
    public:
        Fantassin(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, std::string dir) : CorpsACorps(prix, pv, pointAttaque,pm, dir) {};;
        virtual ~Fantassin();
        void affiche()const;

    protected:

    private:
};

#endif // FANTASSIN_H
