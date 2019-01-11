//Using SDL and standard IO
#include "Terrain.h"
#include "Joueur.h"
#include "Musique.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



void jouer(bool *fin,std::mutex *finMutex)
{
    Terrain* centre = Terrain::getInstanTerrain();

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
    bool fin(false);
    std::mutex finMutex;

    std::thread musiqueThread(music,&fin);
    std::thread jeuThread(jouer,&fin,&finMutex);

    musiqueThread.join();
    jeuThread.join();

    return 0;
}
