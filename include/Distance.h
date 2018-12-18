#ifndef DISTANCE_H
#define DISTANCE_H

#include "Soldat.h"


class Distance : public Soldat
{
    public:
        Distance(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, unsigned int portee, bool dir) : Soldat(prix,pv,pointAttaque,pm, dir),m_portee(portee) {};
        virtual ~Distance();
        virtual void choixCible() {};
        virtual void affiche()const;
    protected:

    private:
        unsigned int m_portee;
};

#endif // DISTANCE_H
