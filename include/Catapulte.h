#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Distance.h"


class Catapulte : public Distance
{
    public:
        Catapulte(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, unsigned int portee, std::string dir) : Distance(prix,pv,pointAttaque,pm,portee, dir) {};
        virtual ~Catapulte();
        void choixCible() {};
    protected:

    private:
};

#endif // CATAPULTE_H
