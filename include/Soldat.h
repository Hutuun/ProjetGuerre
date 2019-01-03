#ifndef SOLDAT_H
#define SOLDAT_H

#include "Unite.h"

class Soldat : public Unite
{
    public:
        Soldat(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, std::string dir,unsigned int pos) : Unite(prix, pv, pointAttaque,dir,pos), m_pm(pm) {};
        virtual ~Soldat();
        virtual void affiche()const {};
        virtual int tour() {return 0;};
        void avancer();
        unsigned int getMouvement();
        virtual int choixCible() {return false;};

    protected:

    private:
        unsigned int positionMax(int j);
        unsigned int m_pm;
};

#endif // SOLDAT_H
