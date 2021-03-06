#ifndef BASE_H
#define BASE_H

#include <iostream>

#include "Batiment.h"

class Base : public Batiment
{
    public:
        Base(std::string  dir,unsigned int pos) : Batiment(0,100,0,dir,pos) {};
        virtual ~Base();
        virtual int choixCible() {return false;};
        void affiche()const;
        virtual int etape1() {return -1;};
        virtual int etape2() {return -1;};
        virtual int etape3(int val) {return -1;};
        //virtual int tour(){return 0;}
        virtual std::string sauvegarde();

    protected:

    private:
};

#endif // BASE_H
