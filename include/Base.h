#ifndef BASE_H
#define BASE_H

#include <iostream>

#include "Batiment.h"

class Base : public Batiment
{
    public:
        Base(std::string  dir) : Batiment(0,100,0,dir) {};
        virtual ~Base();
        void choixCible() {};
        void affiche()const;

    protected:

    private:
};

#endif // BASE_H
