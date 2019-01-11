#include "../../include/Terrain.h"

Terrain* Terrain::m_instance=new Terrain();

Terrain::~Terrain()
{
    for(unsigned int i=0; i<this->m_terrain.size(); i++)
    {
        delete(m_terrain[i]);
    }
    delete(j1);
    delete(j2);
}

void Terrain::initJoueur(Joueur** j, unsigned int pos)
{
    std::string nom;
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> nom;
    char c(0);
    while(c!='O'&&c!='o'&&c!='N'&&c!='n')
    {
        std::cout << "Est-ce une ia ? O/N\n";
        std::cin >> c;
    }
    if(c=='o'||c=='O')
    {
        *j = new IA(nom,pos);
    }
    else
    {
        *j = new Joueur(nom,pos);
    }
}

Terrain::Terrain(): m_terrain(TAILLE),j1(nullptr),j2(nullptr)
{
    char c(0);
    while(c!='O'&&c!='o'&&c!='N'&&c!='n')
    {
        std::cout << "Voulez-vous charger une sauvegarde ? O/N\n";
        std::cin >> c;
    }
    if(c=='o'||c=='O')
    {
        this->chargement();
    }
    initJoueur(&j1,MIN-1);
    initJoueur(&j2,MAX+1);
    for(unsigned int i=0; i<this->m_terrain.size(); i++)
    {
        m_terrain[i]=new Case();
    }
    this->ajoutBases();
}

Terrain* Terrain::getInstanTerrain()
{
    return m_instance;
}

std::vector<Case*> Terrain::getCases()
{
    return m_terrain;
}

void Terrain::affiche()const
{
    for(unsigned int i=0; i<m_terrain.size(); i++)
    {
        std::cout << i+1 << " : ";
        m_terrain[i]->affiche();
    }
}

void Terrain::ajoutBases()
{
    Base *base1=new Base(j1->getNom(),j1->getPos());
    Base *base2=new Base(j2->getNom(),j2->getPos());
    j1->ajoutBase(base1);
    j2->ajoutBase(base2);
    m_terrain[0]->ajoutOccupant(base1);
    m_terrain[m_terrain.size()-1]->ajoutOccupant(base2);
}

bool Terrain::fini()
{
    if(!j1->estVivant())
    {
        std::cout << j2->getNom() << " a gagne !" << std::endl;
        return false;
    }
    else if(!j2->estVivant())
    {
        std::cout << j1->getNom() << " a gagne !" << std::endl;
        return false;
    }
    else
        return true;
}

void Terrain::tue(Soldat*ennemi)
{
    j1->tue(ennemi);
    j2->tue(ennemi);
    m_terrain[ennemi->getPos()]->tue(ennemi);
}

void Terrain::tue(Batiment*ennemi)
{
    j1->tue(ennemi);
    j2->tue(ennemi);
    m_terrain[ennemi->getPos()]->tue(ennemi);
}

bool Terrain::getDir(std::string const nom)const
{
    if(j1->getNom()==nom)
        return j1->getDir();
    else if(j2->getNom()==nom)
        return j2->getDir();
    else
        std::cerr << "Ce joueur n'existe pas";
    return false;
}

void Terrain::ajoutOccupant(Soldat* const occupant,unsigned int pos)
{
    m_terrain[occupant->getPos()]->videCase();
    m_terrain[pos]->ajoutOccupant(occupant);
    occupant->setPos(pos);
}

void Terrain::ajoutOccupant(Batiment* const occupant,unsigned int pos)
{
    m_terrain[occupant->getPos()]->videCase();
    m_terrain[pos]->ajoutOccupant(occupant);
    occupant->setPos(pos);
}

void Terrain::tour()
{
    j1->tourJoueur();
    this->affiche();
    j2->tourJoueur();
    this->affiche();
}

Epoque* Terrain::chargeEpoque(std::string epoque)
{

    if(epoque.compare("Prehistoire")==0)
        return new Prehistoire();
    //Ajouter ici plus d'epoque

    return nullptr;
}

Soldat* Terrain::chargeUnite(std::string unite, std::string dir, unsigned int pv, unsigned int pm, unsigned int porte, unsigned int pos, unsigned int prix, unsigned int pa)
{
    if(unite.compare("Fantassin")==0)
        return new Fantassin(prix,pv,pa,pm,dir,pos,false);
    if(unite.compare("Archer")==0)
        return new Archer(prix,pv,pa,pm,porte,dir,pos);
    if(unite.compare("Catapulte")==0)
        return new Catapulte(prix,pv,pa,pm,porte,dir,pos);
    if(unite.compare("SuperSoldat")==0)
        return new Fantassin(prix,pv,pa,pm,dir,pos,true);

    return nullptr;
}

Batiment* Terrain::chargeBatiment(std::string batiment, std::string dir, unsigned int pv, unsigned int pos, unsigned int prix, unsigned int pa)
{

    if(batiment.compare("Base")==0)
    {
        Base* b = new Base(dir,pos);
        b->setPv(pv);
        return b;
    }


    return nullptr;

}


void Terrain::chargement()
{
    std::string adresse("Donnees/Sauvegarde/");
    std::string nom;
    std::cout << "Entrez le nom de votre sauvegarde : ";
    std::cin >> nom;
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
        std::cout << "La partie n'a pas pu être trouvée\n";
        return;
    }
    std::string tempo = adresse+nom;
    std::ifstream sauvegarde(tempo.c_str());
    if(sauvegarde)
    {
        while(1)
        {
            char* c =(char *)malloc(128);
            sauvegarde.getline(c,128);

            std::string str = c;

            if(str.find("$")==0)
            {

                std::string nom = str.substr(1);
                std::string epoque;
                unsigned int DElor;

                unsigned int pos;
                int ia;



                sauvegarde.getline(c,128);
                epoque = c;

                sauvegarde.getline(c,128);
                DElor = atoi(c);

                sauvegarde.getline(c,128);

                pos = atoi(c);

                sauvegarde.getline(c,128);

                ia = atoi(c);

                if(ia==0)
                {
                    if(pos == 0)
                    {
                        j1 = new IA(nom,pos);
                        j1->ajoutOr(DElor);
                        j1->setEpoque(chargeEpoque(epoque));
                        sauvegarde.getline(c,128); // ICI c'est la base donc pas interessant
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        unsigned int pv = atoi(c);
                        j1->ajoutBase(new Base(nom,pos));
                        j1->getBase()->setPv(pv);
                        sauvegarde.getline(c,128);//fin chargement de la base
                        while(1)
                        {
                            sauvegarde.getline(c,128);
                            if(*c == '$')
                            {
                                break;
                            }
                            std::string bat = c;
                            sauvegarde.getline(c,128);
                            pos = atoi(c);
                            sauvegarde.getline(c,128);
                            unsigned int pa = atoi(c);
                            sauvegarde.getline(c,128);
                            pv = atoi(c);
                            sauvegarde.getline(c,128);
                            unsigned int pp = atoi(c);


                            j1->ajoutBatiment(chargeBatiment(bat,nom,pv,pos,pp,pa));
                        }
                        while(1)
                        {
                            sauvegarde.getline(c,128);
                            if(*c == '$')
                            {
                                break;
                            }
                            std::string unite = c;

                            sauvegarde.getline(c,128);
                            unsigned int porte = atoi(c);
                            sauvegarde.getline(c,128);
                            unsigned int pm = atoi(c);
                            sauvegarde.getline(c,128);
                            pos = atoi(c);
                            sauvegarde.getline(c,128);
                            unsigned int pa = atoi(c);
                            sauvegarde.getline(c,128);
                            pv = atoi(c);
                            sauvegarde.getline(c,128);
                            unsigned int pp = atoi(c);


                            j1->ajoutUnite(chargeUnite(unite,nom,pv,pm,porte,pos,pp,pa));
                        }



                    }
                    else
                    {
                        j2 = new IA(nom,pos);
                        j2->ajoutOr(DElor);
                        j2->setEpoque(chargeEpoque(epoque));
                        sauvegarde.getline(c,128);  // ICI c'est la base (le nom Base) donc pas interessant
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        int pv = atoi(c);
                        j2->ajoutBase(new Base(nom,pos));
                        j2->getBase()->setPv(pv);
                        sauvegarde.getline(c,128);//fin chargement de la base
                    }

                }
                else
                {

                    if(pos == 0)
                    {
                        j1 = new Joueur(nom,pos);
                        j1->ajoutOr(DElor);
                        j1->setEpoque(chargeEpoque(epoque));
                        sauvegarde.getline(c,128); // ICI c'est la base donc pas interessant
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        int pv = atoi(c);
                        j1->ajoutBase(new Base(nom,pos));
                        j1->getBase()->setPv(pv);
                        sauvegarde.getline(c,128);//fin chargement de la base





                    }
                    else
                    {
                        j2 = new Joueur(nom,pos);
                        j2->ajoutOr(DElor);
                        j2->setEpoque(chargeEpoque(epoque));
                        sauvegarde.getline(c,128);  // ICI c'est la base donc pas interessant
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        sauvegarde.getline(c,128);
                        int pv = atoi(c);
                        j2->ajoutBase(new Base(nom,pos));
                        j2->getBase()->setPv(pv);
                        sauvegarde.getline(c,128); //fin chargement de la base
                    }

                }
            }

            if(sauvegarde.eof())
            {
                break;
            }
        }
    }
    else
    {
        std::cout << "Erreur dans la sauvegarde\n";
    }
    closedir(fichier);
}

void Terrain::sauvegarde()
{
    std::string adresse("Donnees/Sauvegarde/");
    std::string nom;
    std::cout << "Entrez le nom de votre sauvegarde : ";
    std::cin >> nom;
    nom +=".txt";
    DIR* fichier = nullptr;
    dirent* dossier = nullptr;
    fichier = opendir(adresse.c_str());
    bool ok(true);
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
    while(dossier!=nullptr)
    {
        if(nom.compare(dossier->d_name)==0)
        {
            char choix;
            while(choix!='O'&&choix!='o'&&choix!='N'&&choix!='n')
            {
                std::cout << "Il y a deja un fichier qui porte ce nom\nVoulez-vous le supprimer ? O/N\n";
                std::cin >> choix;
            }
            if(choix=='n'||choix=='N')
            {
                ok=false;
            }
        }
        dossier = readdir(fichier);
    }
    if(!ok)
    {
        closedir(fichier);
        std::cout << "La partie n'a pas pu être sauvegarder\n";
        return;
    }
    std::string tempo = adresse+nom;
    std::ofstream sauvegarde(tempo.c_str());
    if(sauvegarde)
    {
        sauvegarde << j1->sauvegarde() << "\n" << j2->sauvegarde();
    }
    else
    {
        std::cout << "Erreur dans la sauvegarde\n";
    }
    closedir(fichier);
}
