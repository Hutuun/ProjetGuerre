#include "Prehistoire.h"

Prehistoire::~Prehistoire()
{
    //dtor
}

Fantassin* Prehistoire::getFantassin(std::string nomJoueur, unsigned int pos)
{
    return new Fantassin(10,10,4,1,nomJoueur,pos);
}

Archer* Prehistoire::getArcher(std::string nomJoueur, unsigned int pos)
{
    return new Archer(12,8,3,1,3,nomJoueur,pos);
}

Catapulte* Prehistoire::getCatapulte(std::string nomJoueur, unsigned int pos)
{
    return new Catapulte(20,12,6,1,3,nomJoueur,pos);
}
