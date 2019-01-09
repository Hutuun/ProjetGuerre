#include "../../../include/Catapulte.h"
#include "Terrain.h"

Catapulte::~Catapulte()
{

}

std::string Catapulte::sauvegarde()
{
    std::string res("Catapulte\n");
    res+=Distance::sauvegarde();
    return res;
}

int Catapulte::etape1()
{
    return choixCible();
}

int Catapulte::etape2()
{
    return -1;
}

int Catapulte::etape3(int val)
{
    if(val==-1)
        avancer();
    return -1;
}

/*int Catapulte::tour()
{
    int fait = this->choixCible();
    if(fait==-1)
    {
        this->avancer();
    }
    return fait;
}*/

void Catapulte::affiche() const
{
    std::cout << "Catapulte : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}

int Catapulte::choixCible()
{
    Terrain* ter = Terrain::getInstanTerrain();
    std::vector<Case*> cases = ter->getCases();
    int i=0;
    int res = 0;
    if(ter->getDir(this->m_dir))
    {
        i=1;
    }
    else
    {
        i=-1;
    }
    for(unsigned int j=2; j<this->m_portee+1; j++)
    {
        if((m_pos+(j*i) <= MAX+1) && (m_pos+(j*i) >= MIN-1))
        {
            if((cases[m_pos+(j*i)]->getOccupant() != nullptr) && ( m_dir !=  cases[m_pos+(j*i)]->getOccupant()->getDir() ))
            {
                res = this->attaque(cases[m_pos+(j*i)]->getOccupant());
                if(j < m_portee && m_pos+((j+1)*i) <= MAX+1 && m_pos+((j+1)*i) >= MIN-1)
                {
                    if(cases[m_pos+((j+1)*i)]->getOccupant()!=nullptr)
                        res += this->attaque(cases[m_pos+((j+1)*i)]->getOccupant());
                    else if(cases[m_pos+((j+1)*i)]->getBatiment()!=nullptr)
                        res += this->attaque(cases[m_pos+((j+1)*i)]->getBatiment());
                }
                else if(j==m_portee)
                {
                    if(cases[m_pos+((j-1)*i)]->getOccupant() != nullptr)
                        this->attaque(cases[m_pos+((j-1)*i)]->getOccupant());
                    else if(cases[m_pos+((j-1)*i)]->getBatiment() != nullptr)
                        res += this->attaque(cases[m_pos+((j-1)*i)]->getBatiment());
                }
                return res;
            }
            else if(cases[m_pos+(j*i)]->getBatiment()!=nullptr&&m_dir!=cases[m_pos+(j*i)]->getBatiment()->getDir())
            {
                res = this->attaque(cases[m_pos+(j*i)]->getBatiment());
                if(j<m_portee&&m_pos+((j+1)*i)<=MAX+1&&m_pos+((j+1)*i)>=MIN-1)
                {
                    if(cases[m_pos+((j+1)*i)]->getOccupant()!=nullptr)
                        res += this->attaque(cases[m_pos+((j+1)*i)]->getOccupant());
                    else if(cases[m_pos+((j+1)*i)]->getBatiment()!=nullptr)
                        res += this->attaque(cases[m_pos+((j+1)*i)]->getBatiment());
                }
                else if(j==m_portee)
                {
                    if(cases[m_pos+((j-1)*i)]->getOccupant()!=nullptr)
                        this->attaque(cases[m_pos+((j-1)*i)]->getOccupant());
                    else if(cases[m_pos+((j-1)*i)]->getBatiment()!=nullptr)
                        res += this->attaque(cases[m_pos+((j-1)*i)]->getBatiment());
                }
                return res;
            }
        }
    }
    return -1;
}
