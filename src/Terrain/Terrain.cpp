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
        std::cout << i+1 << " : ";
        m_terrain[i].affiche();
    }
}

void Terrain::ajoutBases()
{
    m_terrain[0].ajoutOccupant(new Base(true));
    m_terrain[m_terrain.size()-1].ajoutOccupant(new Base(false));
}
