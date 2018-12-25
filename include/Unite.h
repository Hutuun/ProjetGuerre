#ifndef UNITE_H
#define UNITE_H

#include <iostream>

class Soldat;
class Batiment;

class Unite
{
    public:
        Unite(unsigned int prix, unsigned int pv, unsigned int pointAttaque, std::string dir, unsigned int pos): m_dir(dir), m_pv(pv),m_pos(pos), m_prix(prix), m_pointAttaque(pointAttaque){};
        virtual ~Unite();
        int attaque(Soldat *ennemi);
        int attaque(Batiment *ennemi);
        bool prendDommage(unsigned int dommage);
        virtual int choixCible() {return false;};
        std::string getDir();
        unsigned int getPrix();
        unsigned int getPos();
        virtual void affiche()const {};
        virtual int tour() {return 0;};
        void setPos(unsigned int i);
        bool estVivant();

    protected:
        std::string m_dir;
        unsigned int m_pv;
        unsigned int m_pos;

    private:
        unsigned int m_prix;
        unsigned int m_pointAttaque;
};

#endif // UNITE_H
