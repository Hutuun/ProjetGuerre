#ifndef ARCHER_H
#define ARCHER_H

#include "Distance.h"


class Archer : public Distance
{
    public:
        Archer(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, unsigned int portee,std::string dir,unsigned int pos) : Distance(prix,pv,pointAttaque,pm,portee, dir,pos) {};
        virtual ~Archer();
        int choixCible();
        int tour();
        void affiche() const;

    protected:

    private:

};

#endif // ARCHER_H
