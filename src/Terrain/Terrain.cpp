#include "../../include/Terrain.h"

Terrain::~Terrain()
{

}

Terrain* Terrain::getInstanTerrain()
{
    if(m_terrain==nullptr)
        m_terrain = new Terrain(11);
    return terrain;
}
