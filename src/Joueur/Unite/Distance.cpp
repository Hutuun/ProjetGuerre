#include "../../../include/Distance.h"

Distance::~Distance()
{
    //dtor
}

std::string Distance::sauvegarde()
{
    std::string res;
    res = m_portee + "\n";
    res += Soldat::sauvegarde();
    return res;
}
