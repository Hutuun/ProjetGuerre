#ifndef UNITE_H
#define UNITE_H

#include "Case.h"

class Case;

class Unite
{
    public:
        Unite(unsigned int prix, unsigned int pv, unsigned int pointAttaque, std::string dir): m_dir(dir), m_pv(pv), m_prix(prix), m_pointAttaque(pointAttaque){};
        virtual ~Unite();
        void attaque(Case &ennemi);
        bool prendDommage(unsigned int dommage);
        virtual void choixCible(unsigned int pos) {};
        std::string getDir();
        virtual void affiche()const {};

    protected:
        std::string m_dir;
        unsigned int m_pv;

    private:
        unsigned int m_prix;
        unsigned int m_pointAttaque;
};

#endif // UNITE_H
