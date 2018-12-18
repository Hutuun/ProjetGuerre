#ifndef BATIMENT_H
#define BATIMENT_H

#include "Unite.h"


class Batiment : public Unite
{
    public:
        Batiment(unsigned int prix, unsigned int pv, unsigned int pointAttaque, std::string  dir):Unite(prix, pv, pointAttaque, dir) {};
        virtual ~Batiment();
        virtual void choixCible() {};
        virtual void affiche()const {};
    protected:

    private:
};

#endif // BATIMENT_H
