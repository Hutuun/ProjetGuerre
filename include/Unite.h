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
        unsigned int prix;
        unsigned int pv;
        unsigned int pointAttaque;
};

#endif // UNITE_H
