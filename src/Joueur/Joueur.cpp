#include "Joueur.h"

using namespace std;

Joueur::~Joueur()
{
    delete(this->m_epoque);
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

void Joueur::tour()
{
    for(unsigned int i=0;i<this->m_troupes.size();i++)
    {

    }
}

Unite& Joueur::acheter()
{
    int choix;
    cout << "Choisissez l'unité que vous voulez acheter\n1)Fantassin\n2)Archer\n3)Catapulte\n";
    cout << "Autre chose pour ne rien acheter" << endl;
    cin >> choix;
    switch(choix)
    {
    case 1:
        if(this->m_or<this->m_epoque.getPrixFantassin())
    }
}
