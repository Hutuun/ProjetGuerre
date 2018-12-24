#include "Fantassin.h"

Fantassin::~Fantassin()
{
    //dtor
}

void Fantassin::tour()
{
    bool fait = this->choixCible();
    this->avancer();
    if(!fait)
    {
        this->choixCible();
    }
}

void Fantassin::affiche() const
{
    std::cout << "Fantassin : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
