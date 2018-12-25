#include "Fantassin.h"

Fantassin::~Fantassin()
{
    //dtor
}

int Fantassin::tour()
{
    int fait = this->choixCible();
    this->avancer();
    if(fait==-1)
    {
        this->choixCible();
    }
    return fait;
}

void Fantassin::affiche() const
{
    std::cout << "Fantassin : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
