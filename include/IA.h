#ifndef IA_H
#define IA_H

#include "Joueur.h"

class IA : public Joueur
{
    public:
        IA(std::string nom, unsigned int pos) : Joueur(nom,pos) {};
        virtual ~IA();
        virtual void tourJoueur();
        virtual bool isIA();

    protected:

    private:
};

#endif // IA_H
