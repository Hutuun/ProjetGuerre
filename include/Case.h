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
        void ajoutOccupant(Soldat* const occupant);
        void tue();
        void affiche()const;
        void videCase();

    protected:

    private:
        bool m_libre;
        Soldat *m_occupant;
        Batiment *m_batiment;
};

#endif // CASE_H
