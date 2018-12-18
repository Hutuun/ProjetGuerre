#ifndef UNITE_H
#define UNITE_H


class Unite
{
    public:
        Unite(unsigned int prix, unsigned int pv, unsigned int pointAttaque): m_prix(prix), m_pv(pv), m_pointAttaque(pointAttaque) {};
        virtual ~Unite();
        void attaque(Unite &ennemi);
        void prendDommage();
        void mourir();
        virtual void choixCible() {};

    protected:

    private:
        unsigned int m_prix;
        unsigned int m_pv;
        unsigned int m_pointAttaque;
};

#endif // UNITE_H
