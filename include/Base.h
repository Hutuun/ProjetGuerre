#ifndef BASE_H
#define BASE_H

#include <iostream>

#include "Batiment.h"

class Base : public Batiment
{
    public:
        Base(std::string  dir,unsigned int pos) : Batiment(0,100,0,dir,pos) {};
        virtual ~Base();
        void choixCible() {};
        void affiche()const;

    protected:

    private:
};

#endif // BASE_H
