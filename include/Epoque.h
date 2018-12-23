#ifndef EPOQUE_H
#define EPOQUE_H

class Epoque
{
    public:
        Epoque();
        virtual ~Epoque();
        virtual int getPrixFantassin();
        virtual int getPrixArcher();
        virtual int getPrixCatapulte();

    protected:

    private:

};

#endif // EPOQUE_H
