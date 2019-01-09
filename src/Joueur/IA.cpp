#include "IA.h"
#include "Case.h"
#include "Terrain.h"

IA::~IA()
{
    //dtor
}

void IA::tourJoueur()
{
    Case *place = Terrain::getInstanTerrain()->getCases()[m_pos];
    this->ajoutOr(8);
    std::cout << "C'est a " << this->getNom() << " de jouer\n";
    this->affiche();
    if(this->estVivant())
    {
        Fantassin* fantassin = this->m_epoque->getFantassin(m_nom,getPos());
        if(m_or>=fantassin->getPrix()&&place->getOccupant()==nullptr)
        {
            m_or-=fantassin->getPrix();
            ajoutUnite(fantassin);
        }
        this->tour();
    }
}

bool IA::isIA()
{
    return true;
}
