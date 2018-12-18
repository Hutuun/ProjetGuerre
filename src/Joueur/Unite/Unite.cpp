#include "../../../include/Unite.h"

Unite::~Unite()
{
    //dtor
}

void Unite::prendDommage(unsigned int dommage)
{
    if(dommage>m_pv)
        this.mourir();
    else
        m_pv-=dommage;
}
