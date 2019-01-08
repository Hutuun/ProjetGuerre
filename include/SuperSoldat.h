#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "Fantassin.h"


class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm, std::string dir,unsigned int pos) : Fantassin(prix, pv, pointAttaque,pm, dir,pos),super(false) {};
        virtual ~SuperSoldat();
        virtual int tour();
        void affiche()const;
        virtual std::string sauvegarde();

    protected:

    private:
        bool super;
};

#endif // SUPERSOLDAT_H
