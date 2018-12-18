#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Distance.h"


class Catapulte : public Distance
{
    public:
        Catapulte();
        virtual ~Catapulte();
        void choixCible() {};

    protected:

    private:
};

#endif // CATAPULTE_H
