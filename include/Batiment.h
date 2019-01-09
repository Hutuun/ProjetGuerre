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
        virtual int etape1() {return -1;};
        virtual int etape2() {return -1;};
        virtual int etape3(int val) {return -1;};
        //virtual int tour() {return 0;};
        virtual std::string sauvegarde();

    protected:

    private:
};

#endif // BATIMENT_H
