CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++17 -ISDL2\i686-w64-mingw32\include -ISFML\include -Iinclude -Wall -std=c++1z -fexceptions -g -std=c++14 -ISDL2\i686-w64-mingw32\include -Isrc\Terrain -c -lmingw32 -lSDL2main -lSDL2  SDL2\i686-w64-mingw32\lib\libSDL2.a SDL2\i686-w64-mingw32\lib\libSDL2.dll.a -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

hello_world: main.o Autre.o Musique.o IA.o Joueur.o Unite.o Archer.o Base.o Batiment.o Catapulte.o CorpsACorps.o Distance.o Fantassin.o Soldat.o Epoque.o Prehistoire.o Case.o Terrain.o
	$(CXX) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 
