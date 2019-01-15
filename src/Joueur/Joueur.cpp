#include "Joueur.h"
#include "Terrain.h"

#define TROU true

using namespace std;

Joueur::~Joueur()
{
    delete (m_base);

    for(unsigned int i=0; i<this->m_batiments.size(); i++)
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
    {
        std::cout << "Ajout d'une unite"<<std::endl;
        Terrain::getInstanTerrain()->ajoutOccupant(troupe,troupe->getPos());
        m_troupes.push_back(troupe);
    }
}

void Joueur::ajoutBatiment(Batiment* batiment)
{
    if(batiment!=nullptr)
    {
        Terrain::getInstanTerrain()->ajoutOccupant(batiment,batiment->getPos());
        m_batiments.push_back(batiment);
    }
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
        if(Terrain::getInstanTerrain()->getCases()[m_pos]->getOccupant()==nullptr)
        {
            ajoutUnite(acheter());
        }
        else
            cout << "Il y a déjà quelqu'un sur votre base\n";
        if(m_troupes.size()!=0)
            this->tour();
    }
}

void Joueur::tour()
{
    vector<int> gold(m_troupes.size());
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        gold[i]=-1;
    }
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        int res = m_troupes[i]->etape1();
        if(res > -1)
        {
            gold[i]=res;
        }
    }
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        int res = m_troupes[i]->etape2();
        if(res > -1)
        {
            gold[i]+=res;
        }
    }
    for(unsigned int i=0; i<this->m_troupes.size(); i++)
    {
        int res = m_troupes[i]->etape3(gold[i]);
        if(res > -1)
        {
            gold[i]+=res;
        }
    }
    int thune=0;
    for(unsigned int i=0;i<this->m_troupes.size();i++)
    {
        if(gold[i]>-1)
            thune += gold[i];
    }
    this->m_or += thune;
}

void Joueur::tue(Soldat* mort)
{
    for(unsigned int i=0; i<m_troupes.size(); i++)
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
    for(unsigned int i=0; i<m_batiments.size(); i++)
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
        cout << "Choisissez l'unite que vous voulez acheter\n0)Sauvegarder\n1)Fantassin : " << fantassin->getPrix() <<"\n2)Archer : " << archer->getPrix() << "\n3)Catapulte : " << catapulte->getPrix() <<"\n";
        cout << "Un autre nombre pour ne rien acheter" << endl;
        cin >> choix;
        switch(choix)
        {
        case 0:
            continu = true;
            Terrain::getInstanTerrain()->sauvegarde();
            break;
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
    //Terrain::getInstanTerrain()->getCases();
    //Terrain::getInstanTerrain()->getCases()[m_pos]->ajoutOccupant(base);
}

bool Joueur::isIA()
{
    return false;
}

void Joueur::setEpoque(Epoque* epo,bool *chgAge,std::string* adresse)
{
    //*adresse = epo->getNom();
    //*chgAge = true;
    m_epoque = epo;
}

std::string Joueur::sauvegarde()
{
    std::string res;
    res = "$" + this->m_nom + "\n" + this->m_epoque->getNom() + "\n"+ convertIntToString(this->m_or) + "\n"+ convertIntToString(this->m_pos) + "\n";
    if(isIA())
        res += "0\n";
    else
        res += "1\n";
    res += this->m_base->sauvegarde();
    for(unsigned int i=0; i<m_batiments.size(); i++)
    {
        res += m_batiments[i]->sauvegarde();
    }
    res += "$\n";
    for(unsigned int i=0; i<m_troupes.size(); i++)
    {
        res += m_troupes[i]->sauvegarde();
    }
    res += "\n$";
    return res;
}
