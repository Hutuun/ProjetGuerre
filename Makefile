CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++17 -ISDL2\i686-w64-mingw32\include -ISFML\include -Iinclude -Wall -std=c++1z -fexceptions -g -std=c++14 -ISDL2\i686-w64-mingw32\include -Isrc\Terrain -c

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

hello_world: main.o src\Autre.o scr\Musique.o scr\Joueur\IA.o scr\Joueur\Joueur.o scr\Joueur\Unite\Unite.o scr\Joueur\Unite\Archer.o scr\Joueur\Unite\Base.o scr\Joueur\Unite\Batiment.o Catapulte.o scr\Joueur\Unite\CorpsACorps.o scr\Joueur\Unite\Distance.o scr\Joueur\Unite\Fantassin.o scr\Joueur\Unite\Soldat.o scr\Joueur\Epoque\Epoque.o scr\Joueur\Epoque\Prehistoire.o scr\Terrain\Case.o scr\Terrain\Terrain.o
	$(CXX) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 
