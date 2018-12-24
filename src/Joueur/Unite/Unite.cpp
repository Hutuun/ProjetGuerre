#include "../../../include/Unite.h"

#include <iostream>

#include "Terrain.h"

Unite::~Unite()
{
    //dtor
}

bool Unite::prendDommage(unsigned int dommage)
{
    if(dommage>m_pv)
    {
        m_pv=0;
        return true;
    }
    else
        m_pv-=dommage;
    return false;
}

bool Unite::attaque(Soldat *ennemi)
{
    if(ennemi==nullptr)
        std::cerr << "Il y a un soucis, il y a personne sur la case choisie";
    else if(ennemi->prendDommage(this->m_pointAttaque))
    {
        Terrain::getInstanTerrain()->tue(ennemi);
        return true;
    }
    return false;
}

bool Unite::attaque(Batiment*ennemi)
{
    if(ennemi==nullptr)
        std::cerr << "Il y a un soucis, il y a pas de batiment sur la case choisie";
    else if(ennemi->prendDommage(this->m_pointAttaque))
    {
        Terrain::getInstanTerrain()->tue(ennemi);
        return true;
    }
    return false;
}

void Unite::setPos(unsigned int i)
{
    m_pos=i;
}

bool Unite::estVivant()
{
    if(this->m_pv==0)
        return false;
    else
        return true;
}

unsigned int Unite::getPos()
{
    return this->m_pos;
}

std::string Unite::getDir()
{
    return m_dir;
}

unsigned int Unite::getPrix()
{
    return this->m_prix;
}
