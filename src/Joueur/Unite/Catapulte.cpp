#include "../../../include/Catapulte.h"
#include "Terrain.h"

Catapulte::~Catapulte()
{

}

void Catapulte::tour()
{
    this->choixCible();
}

void Catapulte::affiche() const
{
    std::cout << "Catapulte : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}

bool Catapulte::choixCible()
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
    for(unsigned int j=0; j<this->m_portee+1; j++)
    {
        if(cases[m_pos+(j*i)]->getOccupant()!=nullptr && m_dir!=cases[m_pos+(j*i)]->getOccupant()->getDir())
        {
            if(j<m_portee)
            {
                this->attaque(*cases[m_pos+((j+1)*i)]);
                return true;
            }
            else if(j==m_portee)
            {
                this->attaque(*cases[m_pos+((j+1)*i)]);
                return true;
            }
        }
    }
    return false;
}
