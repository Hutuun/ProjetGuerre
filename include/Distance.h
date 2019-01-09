#ifndef DISTANCE_H
#define DISTANCE_H

#include "Soldat.h"

class Distance : public Soldat
{
    public:
        Distance(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, unsigned int portee, std::string dir,unsigned int pos) : Soldat(prix,pv,pointAttaque,pm, dir,pos),m_portee(portee) {};
        virtual ~Distance();
        virtual int choixCible() {return false;};
        virtual void affiche()const {};
        unsigned int getPortee() {return m_portee;};
        virtual std::string sauvegarde();

    protected:
        unsigned int m_portee;

    private:

};

#endif // DISTANCE_H
