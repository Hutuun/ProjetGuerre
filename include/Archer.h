#ifndef ARCHER_H
#define ARCHER_H

#include "Distance.h"


class Archer : public Distance
{
    public:
        Archer(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, unsigned int portee) : Distance(prix,pv,pointAttaque,pm,portee) {};
        virtual ~Archer();
        void choixCible() {};
    protected:

    private:

};

#endif // ARCHER_H
