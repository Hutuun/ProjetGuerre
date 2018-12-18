#include "Base.h"

Base::~Base()
{
    //dtor
}

void Base::affiche()const
{
    std::cout << "Base : PV : " << m_pv << " Proprietaire : ";
    if(m_dir)
        std::cout << "J1";
    else
        std::cout << "J2";
    std::cout << std::endl;
}
