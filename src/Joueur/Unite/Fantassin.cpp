#include "Fantassin.h"

Fantassin::~Fantassin()
{
    //dtor
}

void Fantassin::tour()
{
    this->avancer();
}

void Fantassin::affiche() const
{
    std::cout << "Fantassin : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
