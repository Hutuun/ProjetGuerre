CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -ISFML/include -Iinclude -I/src -I/src/Terrain -fexceptions -g -c -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

hello_world: Terrain.o main.o Autre.o Musique.o IA.o Joueur.o Unite.o Archer.o Base.o Batiment.o Catapulte.o CorpsACorps.o Distance.o Fantassin.o Soldat.o Epoque.o Prehistoire.o Case.o Terrain.o
	$(CXX) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 
