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

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
    //The window we'll be rendering to
    /*SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
    	printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
    	//Create window
    	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    	if( window == NULL )
    	{
    		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    	}
    	else
    	{
    		//Get window surface
    		screenSurface = SDL_GetWindowSurface( window );

    		//Fill the surface white
    		SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    		//Update the surface
    		SDL_UpdateWindowSurface( window );

    		//Wait two seconds
    		SDL_Delay( 2000 );
    	}
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();*/

    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/

    /*sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/src/Game_start.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();*/

    /*sf::Music music1;
    if (!music1.openFromFile("D:/Etude/ProjetGuerreEtWar/ProjetGuerre/src/Les_Aigles_Triomphales.wav"))
        return -1; // erreur
    music1.setVolume(50);
    music1.setLoop(true);
    music1.play();*/

    bool fin(false);
    std::mutex finMutex;

    std::thread musiqueThread(music,&fin);
    std::thread jeuThread(jouer,&fin,&finMutex);

    musiqueThread.join();
    jeuThread.join();

    return 0;
}
