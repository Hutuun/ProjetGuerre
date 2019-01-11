#include "Epoque.h"

Epoque::~Epoque()
{
    //dtor
}

std::string Epoque::getNom()const
{
    return this->m_nom;
}

void Epoque::lireFichier()
{
    std::string adresse("Donnees/Epoque/");
    std::string nom(m_nom);
    nom +=".txt";
    DIR* fichier = nullptr;
    dirent* dossier = nullptr;
    fichier = opendir(adresse.c_str());
    bool existe(false);
    if(fichier!=nullptr)
    {
        dossier = readdir(fichier);
        dossier = readdir(fichier);
        dossier = readdir(fichier);
    }
    else
    {
        std::cout << "Soucis fichier\n";
    }
    while(dossier!=nullptr&&!existe)
    {
        if(nom.compare(dossier->d_name)==0)
        {
            existe=true;
        }
        dossier = readdir(fichier);
    }
    if(!existe)
    {
        closedir(fichier);
        std::cout << "La partie n'a pas pu être trouvee\n";
        return;
    }
    std::string tempo = adresse+nom;
    std::ifstream sauvegarde(tempo.c_str());
    if(sauvegarde)
    {
        while(!sauvegarde.eof())
        {
            char* c =(char *)malloc(128);
            sauvegarde.getline(c,128);

            std::string str = c;

            if(str.find("$")==0)
            {


                char* j =(char *)malloc(128);
                std::string nom = str.substr(1);
                int prix;
                int pv;
                int degat;
                int pm;

                sauvegarde.getline(j,128);
                prix = atoi(j);

                sauvegarde.getline(j,128);
                pv = atoi(j);

                sauvegarde.getline(j,128);
                degat = atoi(j);

                sauvegarde.getline(j,128);
                pm = atoi(j);

                if(nom.compare("Fantassin")==0)
                {
                    fantassin = new Fantassin(prix,pv,degat,pm,"",0);
                }
                else if(nom.compare("Archer")==0)
                {
                    int portee;
                    sauvegarde.getline(j,128);
                    portee = atoi(j);
                    archer = new Archer(prix,pv,degat,pm,portee,"",0);
                }
                else if(nom.compare("Catapulte")==0)
                {
                    int portee;
                    sauvegarde.getline(j,128);
                    portee = atoi(j);
                    catapulte = new Catapulte(prix,pv,degat,pm,portee,"",0);
                }

                delete(j);
            }
        }
    }
    else
    {
        std::cout << "Erreur dans la sauvegarde\n";
    }
    closedir(fichier);
}

Fantassin* Epoque::getFantassin(std::string nomJoueur, unsigned int pos)
{
    return new Fantassin(fantassin->getPrix(),fantassin->getPV(),fantassin->getDegat(),fantassin->getMouvement(),nomJoueur,pos);
}

Archer* Epoque::getArcher(std::string nomJoueur, unsigned int pos)
{
    return new Archer(archer->getPrix(),archer->getPV(),archer->getDegat(),archer->getMouvement(),archer->getPortee(),nomJoueur,pos);
}

Catapulte* Epoque::getCatapulte(std::string nomJoueur, unsigned int pos)
{
    return new Catapulte(catapulte->getPrix(),catapulte->getPV(),catapulte->getDegat(),catapulte->getMouvement(),catapulte->getPortee(),nomJoueur,pos);
}
