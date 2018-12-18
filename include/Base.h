#ifndef BASE_H
#define BASE_H

#include "Batiment.h"


class Base : public Batiment
{
    public:
        Base() : Batiment(0,100,0) {};
        virtual ~Base();
        void choixCible() {};



    protected:

    private:
};

#endif // BASE_H
