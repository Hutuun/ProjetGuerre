//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Terrain.h"
#include "Joueur.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <time.h>
#include <thread>
#include <mutex>
#include <fstream>
//#include <experimental/filesystem>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void lireFichierSon()
{
    /*sf::FileInputStream dossier;
    std::cout << dossier.open("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/Donnees") << dossier.getSize();
    if(dossier.open("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/Donnees"))
    {

    }
    else
    {
        std::cout << "Erreur a l'ouverture du fichier son" << std::endl;
    }*/
}

void music(bool *fin)
{
    sf::Music music1;
    if (!music1.openFromFile("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/src/Les_Aigles_Triomphales.wav"))
        return; // erreur
    music1.setVolume(50);
    sf::Music music2;
    if (!music2.openFromFile("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/src/Chant_du_depart.wav"))
        return; // erreur
    music2.setVolume(50);
    sf::Music music3;
    if (!music3.openFromFile("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/src/La_Strasbourgeoise.wav"))
        return; // erreur
    music3.setVolume(50);
    sf::Music music4;
    if (!music4.openFromFile("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/src/Monsieur_de_Turenne.wav"))
        return; // erreur
    music4.setVolume(50);
    srand(time(NULL));
    int nombre_aleatoire = 0;
    while(!*fin)
    {
        nombre_aleatoire = rand()%4;
        switch(nombre_aleatoire)
        {
        case 1:
            music1.play();
            sf::sleep(music1.getDuration());
            break;
        case 2:
            music2.play();
            sf::sleep(music2.getDuration());
            break;
        case 3:
            music3.play();
            sf::sleep(music3.getDuration());
            break;
        case 4:
            music4.play();
            sf::sleep(music4.getDuration());
            break;
        }
    }
}

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
    lireFichierSon();

    /*bool fin(false);
    std::mutex finMutex;

    std::thread musiqueThread(music,&fin);
    std::thread jeuThread(jouer,&fin,&finMutex);

    musiqueThread.join();
    jeuThread.join();*/

    return 0;
}
