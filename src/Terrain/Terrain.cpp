#include "../../include/Terrain.h"

Terrain Terrain::m_instance=Terrain(11);

Terrain::~Terrain()
{

}

Terrain& Terrain::getInstanTerrain()
{
    return m_instance;
}

std::vector<Case> Terrain::getCases()const
{
    return m_terrain;
}

void Terrain::affiche()const
{
    for(unsigned int i=0;i<m_terrain.size();i++)
    {

    }
}
