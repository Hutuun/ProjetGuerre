CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17 -pthread -ISFML/include -Iinclude -Wall -std=c++1z -fexceptions -g -LSFML/sfml-graphics -LSFML/sfml-window -LSFML/sfml-system -LSFML/sfml-audio
EXEC = ProjetGuerre
SRCs = main.cpp src/Autre.cpp src/Musique.cpp src/Joueur/IA.cpp src/Joueur/Joueur.cpp src/Joueur/Unite/Unite.cpp src/Joueur/Unite/Archer.cpp src/Joueur/Unite/Base.cpp src/Joueur/Unite/Batiment.cpp src/Joueur/Unite/Catapulte.cpp src/Joueur/Unite/CorpsACorps.cpp src/Joueur/Unite/Distance.cpp src/Joueur/Unite/Fantassin.cpp src/Joueur/Unite/Soldat.cpp src/Joueur/Epoque/Epoque.cpp src/Joueur/Epoque/Prehistoire.cpp src/Terrain/Case.cpp src/Terrain/Terrain.cpp 
OBJs = $(subst .cpp,.o,$(SRCs))




$(EXEC):$(OBJs)
	$(CXX) $(CXXFLAGS)  -o $@  $< src/Autre.o src/Terrain/Terrain.o src/Musique.o src/Joueur/IA.o src/Joueur/Joueur.o src/Joueur/Unite/Unite.o src/Joueur/Unite/Archer.o src/Joueur/Unite/Base.o src/Joueur/Unite/Batiment.o src/Joueur/Unite/Catapulte.o src/Joueur/Unite/CorpsACorps.o src/Joueur/Unite/Distance.o src/Joueur/Unite/Fantassin.o src/Joueur/Unite/Soldat.o src/Joueur/Epoque/Epoque.o src/Joueur/Epoque/Prehistoire.o src/Terrain/Case.o

%.o:%.cpp %.h
	$(CXX) $(CXXFLAGS)  -o $@ $<

.PHONY: clean

clean:
	rm -rfv $(OBJs)
	