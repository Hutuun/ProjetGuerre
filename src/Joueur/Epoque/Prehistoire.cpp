#include "Prehistoire.h"

Prehistoire::~Prehistoire()
{
    //dtor
}

Fantassin* Prehistoire::getFantassin()
{
    return new Fantassin(0,0,0,0,"rien");
}

Archer* Prehistoire::getArcher()
{
    return new Archer(0,0,0,0,0,"rien");
}

Catapulte* Prehistoire::getCatapulte()
{
    return new Catapulte(0,0,0,0,0,"rien");
}
