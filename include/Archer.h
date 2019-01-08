#ifndef ARCHER_H
#define ARCHER_H

#include "Distance.h"


class Archer : public Distance
{
    public:
        Archer(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, unsigned int portee,std::string dir,unsigned int pos) : Distance(prix,pv,pointAttaque,pm,portee, dir,pos) {};
        virtual ~Archer();
        virtual int choixCible();
        int tour();
        void affiche() const;
        virtual std::string sauvegarde();

    protected:

    private:

};

#endif // ARCHER_H
