#include "../../../include/CorpsACorps.h"

CorpsACorps::~CorpsACorps()
{
    //dtor
}

void CorpsACorps::choixCible(unsigned int pos)
{
    Terrain ter = Terrain::getInstanTerrain();
    std::vector<Case> cases = ter.getCases();
    bool dir=ter.getDir(this->m_dir);
    if(dir)
    {
        if(cases[pos+1].getOccupant()!=nullptr && m_dir!=cases[pos+1].getOccupant()->getDir())
            this->attaque(cases[pos+1]);
    }
    else
    {
        if(cases[pos-1].getOccupant()!=nullptr && m_dir!=cases[pos-1].getOccupant()->getDir())
            this->attaque(cases[pos-1]);
    }
    return;
}
