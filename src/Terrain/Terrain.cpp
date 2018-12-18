#include "../../include/Terrain.h"

Terrain Terrain::m_instance=Terrain(11);

Terrain::~Terrain()
{

}

Terrain::Terrain(unsigned int taille): m_terrain(taille),j1("j1",true),j2("j2",false)
{
    std::string nom;
    std::cout << "Entrez le nom du premier joueur : ";
    std::cin >> nom;
    j1.changeNom(nom);
    std::cout << "Entrez le nom du second joueur : ";
    std::cin >> nom;
    j2.changeNom(nom);
    this->ajoutBases();
}

Terrain& Terrain::getInstanTerrain()
{
    return m_instance;
}

std::vector<Case> Terrain::getCases()const
{
    return m_terrain;
}

void Terrain::affiche()const
{
    for(unsigned int i=0;i<m_terrain.size();i++)
    {
        std::cout << i+1 << " : ";
        m_terrain[i].affiche();
    }
}

void Terrain::ajoutBases()
{
    Base *base1=new Base(j1.getNom());
    Base *base2=new Base(j2.getNom());
    j1.ajoutUnite(base1);
    j2.ajoutUnite(base2);
    m_terrain[0].ajoutOccupant(base1);
    m_terrain[m_terrain.size()-1].ajoutOccupant(base2);
}

bool Terrain::getDir(std::string const nom)const
{
    if(j1.getNom()==nom)
        return j1.getDir();
    else if(j2.getNom()==nom)
        return j2.getDir();
    else
        std::cerr << "Ce joueur n'existe pas";
}
