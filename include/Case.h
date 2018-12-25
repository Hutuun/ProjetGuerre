#ifndef CASE_H
#define CASE_H

#include <cstddef>
#include <iostream>

#include "Soldat.h"
#include "Batiment.h"

class Soldat;
class Batiment;

class Case
{
    public:
        Case() : m_libre(true), m_occupant(nullptr),m_batiment(nullptr) {};
        virtual ~Case();
        Soldat* getOccupant ()const;
        Batiment* getBatiment()const;
        void ajoutOccupant(Soldat* const occupant);
        void tue(Soldat*mort);
        void tue(Batiment*mort);
        void affiche()const;
        void videCase();
        void ajoutBatiment(Batiment* const batiment);

    protected:

    private:
        bool m_libre;
        Soldat *m_occupant;
        Batiment *m_batiment;
};

#endif // CASE_H
