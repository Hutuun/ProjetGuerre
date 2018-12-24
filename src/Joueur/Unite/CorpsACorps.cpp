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
        if(m_pos==MAX)
        {
            if(cases[m_pos+i]->getOccupant()==nullptr)
            {
                this->attaque(*cases[MAX+2]);
                return true;
            }
        }
    }
    else
    {
        i=-1;
        if(m_pos==MIN)
        {
            if(cases[m_pos+i]->getOccupant()==nullptr)
            {
                this->attaque(*cases[MIN-2]);
                return true;
            }
        }
    }
    if(cases[m_pos+i]->getOccupant()!=nullptr && m_dir!=cases[m_pos+i]->getOccupant()->getDir())
    {
        this->attaque(*cases[m_pos+i]);
        return true;
    }
    return false;
}

void CorpsACorps::tour()
{
    this->choixCible();
}
