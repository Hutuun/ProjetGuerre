#include "Fantassin.h"
#include "SuperSoldat.h"

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
        return this->choixCible();
    }
    return fait;
}

void Fantassin::affiche() const
{
    std::cout << "Fantassin : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
