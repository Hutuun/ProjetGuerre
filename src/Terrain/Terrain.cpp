#include "../../include/Terrain.h"

Terrain* Terrain::m_instance=new Terrain(TAILLE);

Terrain::~Terrain()
{
    for(unsigned int i=0;i<this->m_terrain.size();i++)
    {
        delete(m_terrain[i]);
    }
}

Terrain::Terrain(unsigned int taille): m_terrain(taille),j1("j1",true,MIN-1),j2("j2",false,MAX+1)
{
    std::string nom;
    std::cout << "Entrez le nom du premier joueur : ";
    std::cin >> nom;
    j1.changeNom(nom);
    while(nom == j1.getNom())
    {
        std::cout << "Entrez le nom du second joueur : ";
        std::cin >> nom;
    }
    j2.changeNom(nom);
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
    Base *base1=new Base(j1.getNom(),j1.getPos());
    Base *base2=new Base(j2.getNom(),j1.getPos());
    j1.ajoutBase(base1);
    j2.ajoutBase(base2);
    m_terrain[0]->ajoutOccupant(base1);
    m_terrain[m_terrain.size()-1]->ajoutOccupant(base2);
}

bool Terrain::fini()
{
    if(!j1.estVivant())
    {
        std::cout << j2.getNom() << " a gagne !" << std::endl;
        return false;
    }
    else if(!j2.estVivant())
    {
        std::cout << j1.getNom() << " a gagne !" << std::endl;
        return false;
    }
    else
        return true;
}

void Terrain::tue(Case*ennemi)
{
    j1.tue(ennemi->getOccupant());
    j2.tue(ennemi->getOccupant());
    ennemi->tue();
}

bool Terrain::getDir(std::string const nom)const
{
    if(j1.getNom()==nom)
        return j1.getDir();
    else if(j2.getNom()==nom)
        return j2.getDir();
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
    j1.ajoutOr(8);
    j2.ajoutOr(8);
    std::cout << "C'est a " << j1.getNom() << " de jouer\n";
    j1.affiche();
    if(j1.estVivant())
        j1.tour();
    this->affiche();
    std::cout << "C'est a " << j2.getNom() << " de jouer\n";
    j2.affiche();
    if(j2.estVivant())
        j2.tour();
    this->affiche();
}
