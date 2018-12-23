#include "Joueur.h"

using namespace std;

Joueur::~Joueur()
{
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        delete(m_troupes[i]);
    }
}

void Joueur::ajoutUnite(Unite *troupe)
{
    if(troupe!=nullptr)
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
    ajoutUnite(acheter());
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {

    }
}

Unite* Joueur::acheter()
{
    Fantassin* fantassin;
    Archer* archer;
    Catapulte* catapulte;
    bool continu=true;
    while(continu)
    {
        continu=false;
        int choix;
        cout << "Choisissez l'unite que vous voulez acheter\n1)Fantassin\n2)Archer\n3)Catapulte\n";
        cout << "Autre chose pour ne rien acheter" << endl;
        cin >> choix;
        switch(choix)
        {
        case 1:
            fantassin = this->m_epoque->getFantassin(this->m_nom,this->getPos());
            if(this->m_or<fantassin->getPrix())
            {
                continu=true;
                cout << "Vous n'avez pas assez d'or" << endl;
            }
            else
            {
                m_or-=fantassin->getPrix();
                return fantassin;
            }
            break;

        case 2:
            archer = this->m_epoque->getArcher(this->m_nom,this->getPos());
            if(this->m_or<archer->getPrix())
            {
                continu=true;
                cout << "Vous n'avez pas assez d'or" << endl;
            }
            else
            {
                m_or-=archer->getPrix();
                return archer;
            }
            break;

        case 3:
            catapulte = this->m_epoque->getCatapulte(this->m_nom,this->getPos());
            if(this->m_or<catapulte->getPrix())
            {
                continu=true;
                cout << "Vous n'avez pas assez d'or" << endl;
            }
            else
            {
                m_or-=catapulte->getPrix();
                return catapulte;
            }
            break;
        }
    }
    return nullptr;
}

unsigned int Joueur::getPos()const
{
    return this->m_pos;
}
