#include "Fantassin.h"

Fantassin::~Fantassin()
{
    //dtor
}

std::string Fantassin::sauvegarde()
{
    std::string res;
    if(!m_super)
        res = "Fantassin\n";
    else
        res = "SuperSoldat\n";
    res += CorpsACorps::sauvegarde();
    return res;
}

int Fantassin::tour()
{
    int gain(0);
    if(!m_super)
    {
        gain= this->choixCible();
        this->avancer();
        if(gain==-1)
        {
            return this->choixCible();
        }
    }
    else
    {
        gain = this->choixCible();
        this->avancer();
        if(gain==-1)
            gain++;
        gain += this->choixCible();
    }
    if(gain > 0)
    {
        m_super=true;
    }
    return gain;
}

void Fantassin::affiche() const
{
    if(!m_super)
        std::cout << "Fantassin : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
    else
        std::cout << "Super soldat : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
