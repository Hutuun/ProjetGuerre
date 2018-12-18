#include "Base.h"

Base::~Base()
{
    //dtor
}

void Base::affiche()const
{
    std::cout << "Base : PV : " << m_pv << std::endl;
}
