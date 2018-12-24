#include "../../../include/Archer.h"
#include "Terrain.h"

Archer::~Archer()
{
    //dtor
}

void Archer::tour()
{
    this->choixCible();
    this->avancer();
}

void Archer::affiche() const
{
    std::cout << "Archer : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}

bool Archer::choixCible()
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
            this->attaque(cases[m_pos+(j*i)]->getOccupant());
            return true;
        }
        else if(cases[m_pos+i]->getBatiment()!=nullptr&&m_dir!=cases[m_pos+i]->getBatiment()->getDir())
        {
            this->attaque(cases[m_pos+i]->getBatiment());
            return true;
        }
    }
    return false;
}
