#ifndef IA_H
#define IA_H

#include "Joueur.h"

class IA : public Joueur
{
    public:
        IA(std::string nom,bool dir, unsigned int pos) : Joueur(nom,dir,pos) {};
        virtual ~IA();
        virtual void tourJoueur();
        virtual void tour();

    protected:

    private:
};

#endif // IA_H
