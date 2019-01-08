#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "CorpsACorps.h"

class Fantassin : public CorpsACorps
{
    public:
        Fantassin(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, std::string dir,unsigned int pos) : CorpsACorps(prix, pv, pointAttaque,pm, dir,pos) {};
        //Fantassin(Fantassin& fantassin) : Fantassin(fantassin.getPrix(),fantassin.m_pv,fantassin.getDegat(),fantassin.getMouvement(),fantassin.m_dir,fantassin.m_pos) {};
        virtual ~Fantassin();
        void affiche()const;
        virtual int tour();
        virtual std::string sauvegarde();

    protected:

    private:
        void transformation();
};

#endif // FANTASSIN_H
