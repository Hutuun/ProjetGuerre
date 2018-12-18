#include "../../include/Case.h"

Case::~Case()
{
    delete (m_occupant);
}

Unite* Case::getOccupant ()const
{
    return m_occupant;
}

void Case::tue()
{
    m_occupant=nullptr;
}

void Case::ajoutOccupant(Unite* const occupant)
{
    if(m_occupant==nullptr)
        m_occupant=occupant;
    else
        std::cerr << "Il y a deja quelqu'un sur cette case";
}

void Case::affiche()const
{
    if(m_occupant==nullptr)
        std::cout << "0" << std::endl;
    else
        m_occupant->affiche();
}
