#include "Terrain.h"
#include "Joueur.h"
#include "Musique.h"

void jouer(bool *fin,std::mutex *finMutex,bool *chgAge,std::string *adresse)
{
    Terrain* centre = Terrain::getInstanTerrain(chgAge,adresse);
    centre->init();

    centre->affiche();

    while(centre->fini())
    {
        centre->tour();
    }
    finMutex->lock();
    *fin = true;
    finMutex->unlock();
}

int main( int argc, char* args[] )
{
    bool fin(false),chgAge(false);
    std::string adresse("Prehistoire/");
    std::mutex finMutex;

    std::thread musiqueThread(music,&fin,&chgAge,&adresse);
    std::thread jeuThread(jouer,&fin,&finMutex,&chgAge,&adresse);

    musiqueThread.join();
    jeuThread.join();

    return 0;
}
