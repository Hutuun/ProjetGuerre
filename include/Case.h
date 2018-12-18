#ifndef CASE_H
#define CASE_H

#include <cstddef>
#include <iostream>

#include "Unite.h"

class Unite;

class Case
{
    public:
        Case() : m_libre(true), occupant(nullptr) {};
        virtual ~Case();

    protected:

    private:
        bool m_libre;
        Unite *occupant;
};

#endif // CASE_H
