#include "../../../include/Archer.h"
#include "Terrain.h"

Archer::~Archer()
{
    //dtor
}

int Archer::tour()
{
    int gain = this->choixCible();
    this->avancer();
    return gain;
}

void Archer::affiche() const
{
    std::cout << "Archer : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}

int Archer::choixCible()
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
            return this->attaque(cases[m_pos+(j*i)]->getOccupant());
        }
        else if(cases[m_pos+i]->getBatiment()!=nullptr&&m_dir!=cases[m_pos+i]->getBatiment()->getDir())
        {
            return this->attaque(cases[m_pos+i]->getBatiment());
        }
    }
    return -1;
}
