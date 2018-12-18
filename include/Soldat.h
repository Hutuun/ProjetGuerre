#ifndef SOLDAT_H
#define SOLDAT_H

#include "Unite.h"

class Soldat : public Unite
{
    public:
        virtual void choixCible() {};
        Soldat(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, std::string dir) : Unite(prix, pv, pointAttaque,dir), m_pm(pm) {};
        virtual ~Soldat();
        virtual void affiche()const {};
    protected:

    private:
        unsigned int m_pm;
};

#endif // SOLDAT_H
