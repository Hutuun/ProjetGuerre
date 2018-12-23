#include "../../../include/Catapulte.h"

Catapulte::~Catapulte()
{

}

void Catapulte::tour()
{
    this->choixCible();
}

void Catapulte::affiche() const
{
    std::cout << "Catapulte : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
