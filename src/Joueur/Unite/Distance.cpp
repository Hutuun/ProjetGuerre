#include "../../../include/Distance.h"
#include "Autre.h"

Distance::~Distance()
{
    //dtor
}

std::string Distance::sauvegarde()
{
    std::string res;
    res = convertIntToString(m_portee) + "\n";
    res += Soldat::sauvegarde();
    return res;
}
