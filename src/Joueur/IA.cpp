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
        Fantassin* fantassin = this->m_epoque->getFantassin(m_nom,getPos());
        if(m_or>=fantassin->getPrix())
        {
            m_or-=fantassin->getPrix();
            ajoutUnite(fantassin);
        }
        this->tour();
    }
}
