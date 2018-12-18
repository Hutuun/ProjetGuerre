#ifndef BASE_H
#define BASE_H

#include "Batiment.h"


class Base : public Batiment
{
    public:
        Base();
        virtual ~Base();
        void choixCible() {};
    protected:

    private:
};

#endif // BASE_H
