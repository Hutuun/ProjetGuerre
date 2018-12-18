#ifndef FANTASSIN_H
#define FANTASSIN_H

#include <CorpsACorps.h>


class Fantassin : public CorpsACorps
{
    public:
        Fantassin(unsigned int prix, unsigned int pv, unsigned int pointAttaque,unsigned int pm);
        virtual ~Fantassin();

    protected:

    private:
};

#endif // FANTASSIN_H
