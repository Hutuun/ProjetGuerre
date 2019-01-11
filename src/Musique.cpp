#include "Musique.h"

std::vector<std::string> lireFichierSon(std::string adresse)
{
    std::vector<std::string> res;
    DIR* fichier = nullptr;
    dirent* dossier = nullptr;
    fichier = opendir(adresse.c_str());
    if(fichier!=nullptr)
    {
        dossier = readdir(fichier);
        dossier = readdir(fichier);
        dossier = readdir(fichier);
    }
    else
    {
        std::cout << "Soucis fichier\n";
        return res;
    }
    while(dossier!=nullptr)
    {
        res.push_back(dossier->d_name);
        dossier = readdir(fichier);
    }
    closedir(fichier);
    return res;
}

bool estWav(std::string fichier)
{
    size_t found = fichier.find_last_of(".");
    if(found==std::string::npos)
    {
        return false;
    }
    else if(fichier.substr(found+1).compare("wav")==0)
    {
        return true;
    }
    return false;
}

sf::Music* wavJouable(std::string fichier)
{
    sf::Music* music = new sf::Music();
    if (!music->openFromFile("Donnees/Musique/" + fichier))
    {
        std::cout << "Il y a une erreur dans le chargement des musiques" << std::endl;
        return nullptr;
    }
    return music;
}

void laFinDuMonde(bool *fin,sf::Time *duree)
{
    sf::Clock clock;
    while(clock.getElapsedTime()<*duree&&!*fin)
    {
        sf::sleep(sf::seconds(1));
    }
    return;
}

void music(bool *fin,bool *chgAge,std::string *adresse)
{

    std::vector<std::string> listeMusique(lireFichierSon("Donnees/Musique/" + *adresse));
    std::vector<sf::Music*> listeJouable;
    for(unsigned int i=0; i<listeMusique.size(); i++)
    {
        if(estWav(listeMusique[i]))
        {
            sf::Music* music = wavJouable(listeMusique[i]);
            if(music != nullptr)
                listeJouable.push_back(music);
        }
    }

    srand(time(NULL));
    int nombre_aleatoire = 0;

    while(!*fin)
    {
        if(chgAge)
        {
            std::vector<std::string> listeMusique(lireFichierSon("Donnees/Musique/" + *adresse));
            std::vector<sf::Music*> listeJouable;
            for(unsigned int i=0; i<listeMusique.size(); i++)
            {
                if(estWav(listeMusique[i]))
                {
                    sf::Music* music = wavJouable(listeMusique[i]);
                    if(music != nullptr)
                        listeJouable.push_back(music);
                }
            }
        }
        nombre_aleatoire = rand()%listeJouable.size();
        listeJouable[nombre_aleatoire]->play();
        sf::Time time(listeJouable[nombre_aleatoire]->getDuration());
        std::thread attendThread(laFinDuMonde,fin,&time);
        attendThread.join();
        listeJouable[nombre_aleatoire]->stop();
    }
    return;
}
