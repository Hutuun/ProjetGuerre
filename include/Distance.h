#ifndef DISTANCE_H
#define DISTANCE_H

#include "Soldat.h"


class Distance : public Soldat
{
    public:
        Distance(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, unsigned int portee) : Soldat(prix,pv,pointAttaque,pm),m_portee(portee) {};
        virtual ~Distance();
        virtual void choixCible() {};
    protected:

    private:
        unsigned int m_portee;
};

#endif // DISTANCE_H
