#include "CorpsACorps.h"
#include "Terrain.h"

CorpsACorps::~CorpsACorps()
{
    //dtor
}

bool CorpsACorps::choixCible()
{
    Terrain* ter = Terrain::getInstanTerrain();
    std::vector<Case*> cases = ter->getCases();
    int i=0;
    if(ter->getDir(this->m_dir))
    {
        i=1;
    }
    else
    {
        i=-1;
    }
    if(cases[m_pos+i]->getOccupant()!=nullptr && m_dir!=cases[m_pos+i]->getOccupant()->getDir())
    {
        this->attaque(cases[m_pos+i]->getOccupant());
        return true;
    }
    else if(cases[m_pos+i]->getBatiment()!=nullptr&&m_dir!=cases[m_pos+i]->getBatiment()->getDir())
    {
        this->attaque(cases[m_pos+i]->getBatiment());
        return true;
    }
    return false;
}

void CorpsACorps::tour()
{
    this->choixCible();
}
