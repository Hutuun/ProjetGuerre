#include "../../../include/Distance.h"

Distance::~Distance()
{
    //dtor
}

void Distance::sauvegarde(std::ofstream fsauvegarde)
{
    fsauvegarde << m_portee << "\n";
    Soldat::sauvegarde(fsauvegarde);
}
