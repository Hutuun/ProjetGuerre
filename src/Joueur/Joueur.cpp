#include "Joueur.h"

Joueur::~Joueur()
{
    //dtor
}

void Joueur::ajoutUnite(Unite *troupe)
{
    m_troupes.push_back(troupe);
}

void Joueur::changeNom(std::string nom)
{
    m_nom=nom;
}

std::string Joueur::getNom()const
{
    return m_nom;
}

bool Joueur::getDir()const
{
    return m_dir;
}
