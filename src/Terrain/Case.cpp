#include "../../include/Case.h"

Case::~Case()
{
    delete (m_occupant);
    delete (m_batiment);
}

Soldat* Case::getOccupant ()const
{
    return m_occupant;
}

Batiment* Case::getBatiment ()const
{
    return this->m_batiment;
}

void Case::tue(Soldat*mort)
{
    if(m_occupant==mort)
        m_occupant=nullptr;
    else
        std::cerr << "Il y a un soucis tu es perdu\n";
}

void Case::tue(Batiment*mort)
{
    if(m_batiment==mort)
        m_batiment=nullptr;
    else
        std::cerr << "Il y a un soucis tu es perdu\n";
}

void Case::ajoutOccupant(Batiment* const batiment)
{
    if(m_batiment==nullptr)
        m_batiment=batiment;
    else
        std::cerr << "Il y a deja un batiment sur cette case";
}

void Case::ajoutOccupant(Soldat* const occupant)
{
    if(m_occupant==nullptr)
        m_occupant=occupant;
    else
        std::cerr << "Il y a deja quelqu'un sur cette case";
}

void Case::affiche()const
{
    if(m_occupant != nullptr || m_batiment != nullptr)
    {
        if(m_occupant != nullptr)
            m_occupant->affiche();
        if(m_batiment != nullptr)
            m_batiment->affiche();
    }
    else
        std::cout << "0" << std::endl;
}

void Case::videCase()
{
    this->m_occupant=nullptr;
}
