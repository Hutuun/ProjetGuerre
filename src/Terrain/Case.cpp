#include "../../include/Case.h"

Case::~Case()
{
    delete (occupant);
}

Unite* Case::getOccupant ()const
{
    return occupant;
}

void Case::tue()
{
    this->occupant=nullptr;
}
