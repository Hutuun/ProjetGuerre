#ifndef UNITE_H
#define UNITE_H

#include "Case.h"

class Case;

class Unite
{
    public:
        Unite(unsigned int prix, unsigned int pv, unsigned int pointAttaque, bool dir): m_dir(dir), m_prix(prix), m_pv(pv), m_pointAttaque(pointAttaque){};
        virtual ~Unite();
        void attaque(Case &ennemi);
        bool prendDommage(unsigned int dommage);
        virtual void choixCible(unsigned int pos) {};
        bool getDir();
        virtual void affiche()const;

    protected:
        bool m_dir;

    private:
        unsigned int m_prix;
        unsigned int m_pv;
        unsigned int m_pointAttaque;
};

#endif // UNITE_H
