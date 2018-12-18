#ifndef UNITE_H
#define UNITE_H

#include "Case.h"

class Case;

class Unite
{
    public:
        Unite(unsigned int prix, unsigned int pv, unsigned int pointAttaque): m_prix(prix), m_pv(pv), m_pointAttaque(pointAttaque) {mort=false;};
        virtual ~Unite();
        void attaque(Case &ennemi);
        bool prendDommage(unsigned int dommage);
        virtual void choixCible() {};

    protected:

    private:
        bool mort;
        unsigned int m_prix;
        unsigned int m_pv;
        unsigned int m_pointAttaque;
};

#endif // UNITE_H
