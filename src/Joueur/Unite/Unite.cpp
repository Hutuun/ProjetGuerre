#include "../../../include/Unite.h"

#include <iostream>

Unite::~Unite()
{
    //dtor
}

bool Unite::prendDommage(unsigned int dommage)
{
    if(dommage>m_pv)
        return true;
    else
        m_pv-=dommage;
    return false;
}

void Unite::attaque(Case &ennemi)
{
    if(ennemi.getOccupant()==nullptr)
        std::cerr << "Il y a un soucis";
    else if(ennemi.getOccupant()->prendDommage(this->m_pointAttaque))
        ennemi.tue();
}
