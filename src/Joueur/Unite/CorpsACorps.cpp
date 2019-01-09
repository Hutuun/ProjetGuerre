#include "CorpsACorps.h"
#include "Terrain.h"

CorpsACorps::~CorpsACorps()
{
    //dtor
}

int CorpsACorps::choixCible()
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
        return this->attaque(cases[m_pos+i]->getOccupant());
    }
    else if(cases[m_pos+i]->getBatiment()!=nullptr&&m_dir!=cases[m_pos+i]->getBatiment()->getDir())
    {
        return this->attaque(cases[m_pos+i]->getBatiment());
    }
    return -1;
}

std::string CorpsACorps::sauvegarde()
{
    return convertIntToString(0)+ "\n" + Soldat::sauvegarde();
}
