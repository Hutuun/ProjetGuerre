#include "../../../include/Archer.h"

Archer::~Archer()
{
    //dtor
}

void Archer::tour()
{
    this->choixCible();
}

void Archer::affiche() const
{
    std::cout << "Archer : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
