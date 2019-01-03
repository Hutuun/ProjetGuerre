#include "SuperSoldat.h"

SuperSoldat::~SuperSoldat()
{
    //dtor
}

int SuperSoldat::tour()
{
    int gain(0);
    if(!super)
    {
        gain = Fantassin::tour();
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
        super=true;
    }
    return gain;
}

void SuperSoldat::affiche() const
{
    if(!super)
        Fantassin::affiche();
    else
        std::cout << "Super soldat : PV : " << m_pv << " Proprietaire : " << m_dir << std::endl;
}
