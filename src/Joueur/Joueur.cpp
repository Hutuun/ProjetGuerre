#include "Joueur.h"

using namespace std;

Joueur::~Joueur()
{
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        delete(m_troupes[i]);
    }
}

void Joueur::ajoutUnite(Soldat *troupe)
{
    if(troupe!=nullptr)
        m_troupes.push_back(troupe);
}

void Joueur::ajoutBatiment(Batiment* batiment)
{
    if(batiment!=nullptr)
        m_batiments.push_back(batiment);
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

bool Joueur::estVivant()
{
    if(this->m_base->estVivant())
        return true;
    else
        return false;
}

void Joueur::tour()
{
    ajoutUnite(acheter());
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        m_troupes[i]->tour();
    }
}

void Joueur::tue(Soldat* mort)
{
    for(unsigned int i=0;i<m_troupes.size();i++)
    {
        if(m_troupes[i]==mort)
        {
            m_troupes.erase(m_troupes.begin()+i);
            return;
        }
    }
}

void Joueur::affiche()const
{
    std::cout << "Nom : " << this->m_nom << " Or : " << this->m_or << " Epoque : " << this->m_epoque->getNom() << "\n";
}

Soldat* Joueur::acheter()
{
    Fantassin* fantassin = this->m_epoque->getFantassin(m_nom,getPos());
    Archer* archer = this->m_epoque->getArcher(m_nom,getPos());
    Catapulte* catapulte = this->m_epoque->getCatapulte(m_nom,getPos());
    bool continu=true;
    while(continu)
    {
        continu=false;
        int choix;
        cout << "Choisissez l'unite que vous voulez acheter\n1)Fantassin : " << fantassin->getPrix() <<"\n2)Archer : " << archer->getPrix() << "\n3)Catapulte : " << catapulte->getPrix() <<"\n";
        cout << "Autre chose pour ne rien acheter" << endl;
        cin >> choix;
        switch(choix)
        {
        case 1:
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

Base* Joueur::getBase()
{
    return this->m_base;
}

void Joueur::ajoutOr(unsigned int argent)
{
    this->m_or+=argent;
}

unsigned int Joueur::getPos()const
{
    return this->m_pos;
}

void Joueur::ajoutBase(Base* base)
{
    m_base=base;
}
