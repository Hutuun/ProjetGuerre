#include "Soldat.h"
#include "Terrain.h"

Soldat::~Soldat()
{
    //dtor
}

unsigned int Soldat::positionMax(int j)
{
    Terrain* place = Terrain::getInstanTerrain();
    for(unsigned int i=1;i<this->m_pm+1;i++)
    {
        if(place->getCases()[m_pos+(i*j)]->getOccupant()!=nullptr)
        {
            return this->m_pos+((i-1)*j);
        }
        else if(place->getCases()[m_pos+(i*j)]->getBatiment()!=nullptr && place->getCases()[m_pos+(i*j)]->getBatiment()->getDir()!=this->m_dir)
        {
            return this->m_pos+((i-1)*j);
        }
    }
    return (m_pm*j)+m_pos;
}

void Soldat::avancer()
{
    Terrain* place = Terrain::getInstanTerrain();
    int j=0;
    if(place->getDir(this->m_dir))
    {
        j=1;
        if(m_pos==MAX)
            return;
    }
    else
    {
        j=-1;
        if(m_pos==MIN)
            return;
    }
    place->ajoutOccupant(this,positionMax(j));
}

unsigned int Soldat::getMouvement()
{
    return this->m_pm;
}
