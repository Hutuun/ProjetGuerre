#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Distance.h"


class Catapulte : public Distance
{
    public:
        Catapulte(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, unsigned int portee, std::string dir,unsigned int pos) : Distance(prix,pv,pointAttaque,pm,portee, dir,pos) {};
        virtual ~Catapulte();
        bool choixCible();
        void tour();
        void affiche() const;

    protected:

    private:
};

#endif // CATAPULTE_H
