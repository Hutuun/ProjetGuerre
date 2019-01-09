#include "Base.h"

Base::~Base()
{
    //dtor
}

void Base::affiche()const
{
    std::cout << "Base : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}

std::string Base::sauvegarde()
{
    return "Base\n" + Batiment::sauvegarde();
}
