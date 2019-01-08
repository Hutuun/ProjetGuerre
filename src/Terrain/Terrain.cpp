#include "../../include/Terrain.h"

Terrain* Terrain::m_instance=new Terrain();

Terrain::~Terrain()
{
    for(unsigned int i=0;i<this->m_terrain.size();i++)
    {
        delete(m_terrain[i]);
    }
}

void Terrain::initJoueur(Joueur* j,bool dir, unsigned int pos)
{
    std::string nom;
    std::cout << "Entrez le nom du premier joueur : ";
    std::cin >> nom;
    char c;
    while(c!='O'||c!='o'||c!='N'||c!='n')
    {
        std::cout << "Est-ce une ia ? O/N\n";
        std::cin >> c;
    }
    if(c=='o'||c=='O')
    {
        j = new IA(nom,dir,pos);
    }
    else
    {
        j = new Joueur(nom,dir,pos);
    }
}

Terrain::Terrain(): m_terrain(TAILLE),j1(nullptr),j2(nullptr)
{
    initJoueur(j1,true,MIN-1);
    initJoueur(j2,false,MAX+1);
    for(unsigned int i=0;i<this->m_terrain.size();i++)
    {
        m_terrain[i]=new Case();
    }
    this->ajoutBases();
}

Terrain* Terrain::getInstanTerrain()
{
    return m_instance;
}

std::vector<Case*> Terrain::getCases()
{
    return m_terrain;
}

void Terrain::affiche()const
{
    for(unsigned int i=0; i<m_terrain.size(); i++)
    {
        std::cout << i+1 << " : ";
        m_terrain[i]->affiche();
    }
}

void Terrain::ajoutBases()
{
    Base *base1=new Base(j1->getNom(),j1->getPos());
    Base *base2=new Base(j2->getNom(),j1->getPos());
    j1->ajoutBase(base1);
    j2->ajoutBase(base2);
    m_terrain[0]->ajoutBatiment(base1);
    m_terrain[m_terrain.size()-1]->ajoutBatiment(base2);
}

bool Terrain::fini()
{
    if(!j1->estVivant())
    {
        std::cout << j2->getNom() << " a gagne !" << std::endl;
        return false;
    }
    else if(!j2->estVivant())
    {
        std::cout << j1->getNom() << " a gagne !" << std::endl;
        return false;
    }
    else
        return true;
}

void Terrain::tue(Soldat*ennemi)
{
    j1->tue(ennemi);
    j2->tue(ennemi);
    m_terrain[ennemi->getPos()]->tue(ennemi);
}

void Terrain::tue(Batiment*ennemi)
{
    j1->tue(ennemi);
    j2->tue(ennemi);
    m_terrain[ennemi->getPos()]->tue(ennemi);
}

bool Terrain::getDir(std::string const nom)const
{
    if(j1->getNom()==nom)
        return j1->getDir();
    else if(j2->getNom()==nom)
        return j2->getDir();
    else
        std::cerr << "Ce joueur n'existe pas";
    return false;
}

void Terrain::ajoutOccupant(Soldat* const occupant,unsigned int pos)
{
    m_terrain[occupant->getPos()]->videCase();
    m_terrain[pos]->ajoutOccupant(occupant);
    occupant->setPos(pos);
}

void Terrain::tour()
{
    j1->tourJoueur();
    this->affiche();
    j2->tourJoueur();
    this->affiche();
}
