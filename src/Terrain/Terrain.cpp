#include "../../include/Terrain.h"

Terrain Terrain::m_instance=Terrain(11);

Terrain::~Terrain()
{

}

Terrain& Terrain::getInstanTerrain()
{
    return m_instance;
}
