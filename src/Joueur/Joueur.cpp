#include "Joueur.h"
#include "Terrain.h"

#define TROU true

using namespace std;

Joueur::~Joueur()
{
    delete (m_base);

    for(unsigned int i=0; i<this->m_batiments.size();i++)
    {
        delete(m_batiments[i]);
    }

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
    if(m_pos==0)
        return true;
    else
        return false;
}

bool Joueur::estVivant()
{
    if(this->m_base->estVivant())
        return true;
    else
        return false;
}

void Joueur::tourJoueur()
{
    this->ajoutOr(8);
    std::cout << "C'est a " << this->getNom() << " de jouer\n";
    this->affiche();
    if(this->estVivant())
    {
        ajoutUnite(acheter());
        this->tour();
    }
}

void Joueur::tour()
{
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        int res = m_troupes[i]->tour();
        if(res > 0)
        {
            this->m_or+=res;
        }
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

void Joueur::tue(Batiment* mort)
{
    for(unsigned int i=0;i<m_batiments.size();i++)
    {
        if(m_batiments[i]==mort)
        {
            m_batiments.erase(m_batiments.begin()+i);
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
        cout << "Choisissez l'unite que vous voulez acheter\n0)Sauvegarder\n1)Charger une sauvegarde2)Fantassin : " << fantassin->getPrix() <<"\n3)Archer : " << archer->getPrix() << "\n4)Catapulte : " << catapulte->getPrix() <<"\n";
        cout << "Un autre nombre pour ne rien acheter" << endl;
        cin >> choix;
        switch(choix)
        {
        case 0:
            continu = true;
            Terrain::getInstanTerrain()->sauvegarde();
            break;
        case 1:
            continu = true;
            Terrain::getInstanTerrain()->chargement();
            break;
        case 2:
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

        case 3:
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

        case 4:
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

bool Joueur::isIA()
{
    return false;
}

std::string Joueur::sauvegarde()
{
    std::string res;
    res = this->m_nom + "\n" + this->m_epoque->getNom() + "\n"+ convertIntToString(this->m_or) + "\n"+ convertIntToString(this->m_pos) + "\n";
    if(isIA())
        res += "0\n";
    else
        res += "1\n";
    res += this->m_base->sauvegarde();
    for(unsigned int i=0;i<m_batiments.size();i++)
    {
        res += m_batiments[i]->sauvegarde();
    }
    for(unsigned int i=0;i<m_troupes.size();i++)
    {
        res += m_troupes[i]->sauvegarde();
    }
    return res;
}
