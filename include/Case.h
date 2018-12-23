#ifndef CASE_H
#define CASE_H

#include <cstddef>
#include <iostream>

#include "Unite.h"

class Unite;

class Case
{
    public:
        Case() : m_libre(true), m_occupant(nullptr) {};
        virtual ~Case();
        Unite* getOccupant ()const;
        void ajoutOccupant(Unite* const occupant);
        void tue();
        void affiche()const;
        void videCase();

    protected:

    private:
        bool m_libre;
        Unite *m_occupant;
};

#endif // CASE_H
