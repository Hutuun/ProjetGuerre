#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Distance.h"


class Catapulte : public Distance
{
    public:
        Catapulte(unsigned int prix, unsigned int pv, unsigned int pointAttaque, unsigned int pm, unsigned int portee, std::string dir,unsigned int pos) : Distance(prix,pv,pointAttaque,pm,portee, dir,pos) {};
        virtual ~Catapulte();
        int choixCible();
        //int tour();
        virtual int etape1();
        virtual int etape2();
        virtual int etape3(int val);
        void affiche() const;
        virtual std::string sauvegarde();

    protected:

    private:
};

#endif // CATAPULTE_H
