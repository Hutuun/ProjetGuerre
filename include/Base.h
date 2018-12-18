#ifndef BASE_H
#define BASE_H

#include "Batiment.h"


class Base : public Batiment
{
    public:
        Base(bool dir) : Batiment(0,100,0,dir) {};
        virtual ~Base();
        void choixCible() {};


    protected:

    private:
};

#endif // BASE_H
