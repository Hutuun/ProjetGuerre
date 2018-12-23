#include "CorpsACorps.h"
#include "Terrain.h"

CorpsACorps::~CorpsACorps()
{
    //dtor
}

void CorpsACorps::choixCible()
{
    Terrain ter = Terrain::getInstanTerrain();
    std::vector<Case> cases = ter.getCases();
    bool dir=ter.getDir(this->m_dir);
    if(dir)
    {
        if(cases[m_pos+1].getOccupant()!=nullptr && m_dir!=cases[m_pos+1].getOccupant()->getDir())
            this->attaque(cases[m_pos+1]);
    }
    else
    {
        if(cases[m_pos-1].getOccupant()!=nullptr && m_dir!=cases[m_pos-1].getOccupant()->getDir())
            this->attaque(cases[m_pos-1]);
    }
    return;
}

void CorpsACorps::tour()
{
    this->choixCible();
}
