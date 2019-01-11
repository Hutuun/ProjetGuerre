#ifndef MUSIQUE_H_INCLUDED
#define MUSIQUE_H_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <stdio.h>
#include <thread>
#include <mutex>
#include <time.h>
#include <mutex>
#include <fstream>
#include <dirent.h>
#include <string>
#include <vector>
#include <iostream>

void music(bool *fin,bool *chgAge,std::string *adresse);

#endif // MUSIQUE_H_INCLUDED
