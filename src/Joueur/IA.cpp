#include "IA.h"

IA::~IA()
{
    //dtor
}

void IA::tourJoueur()
{
    this->ajoutOr(8);
    std::cout << "C'est a " << this->getNom() << " de jouer\n";
    this->affiche();
    if(this->estVivant())
    {
        this->tour();
    }
}

void IA::tour()
{
    Terrain place = Terrain::getInstanTerrain();
    if(m_or>this)
}
