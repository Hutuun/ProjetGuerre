#ifndef BATIMENT_H
#define BATIMENT_H

#include "Unite.h"

class Batiment : public Unite
{
    public:
        Batiment(unsigned int prix, unsigned int pv, unsigned int pointAttaque, std::string  dir,unsigned int pos):Unite(prix, pv, pointAttaque, dir,pos) {};
        virtual ~Batiment();
        virtual int choixCible() {return false;};
        virtual void affiche()const {};
        virtual int tour() {return 0;};
    protected:

    private:
};

#endif // BATIMENT_H
