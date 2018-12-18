#ifndef ARCHER_H
#define ARCHER_H

#include "Distance.h"


class Archer : public Distance
{
    public:
        Archer();
        virtual ~Archer();
        void choixCible() {};

    protected:

    private:
};

#endif // ARCHER_H
