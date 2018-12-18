#ifndef UNITE_H
#define UNITE_H


class Unite
{
    public:
        Unite();
        virtual ~Unite();
        void attaque(Unite &ennemi);
        void prendDommage();
        void mourir();
        virtual void choixCible() {};

    protected:

    private:
        unsigned double prix;
        unsigned int pv;
        unsigned int pa;
};

#endif // UNITE_H
