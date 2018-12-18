#include "../../../include/Unite.h"

Unite::~Unite()
{
    //dtor
}

bool Unite::prendDommage(unsigned int dommage)
{
    if(dommage>m_pv)
        return true;
    else
        m_pv-=dommage;
    return false;
}
