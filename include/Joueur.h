#ifndef JOUEUR_H
#define JOUEUR_H

#include"Unite.h"

class Unite;

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();

        Unite& acheter();

    protected:

    private:
        unsigned int m_or;
};

#endif // JOUEUR_H
