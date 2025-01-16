#Variables
COMPIL = g++
EDL = g++
OPTIONS = -ansi -pedantic -Wall -std=c++11

# Ajout de l'option MAP si définie
ifdef MAP
	OPTIONS += -DMAP
endif

#Compilation du programme principal

trajets: main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o ListeTrajet.o Catalogue.o
	$(EDL) $(OPTIONS) -o trajets main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o ListeTrajet.o Catalogue.o

#Compilation des fichiers source

main.o: main.cpp
	$(COMPIL) $(OPTIONS) -c main.cpp

TrajetCompose.o: TrajetCompose.cpp
	$(COMPIL) $(OPTIONS) -c TrajetCompose.cpp

Catalogue.o: Catalogue.cpp
	$(COMPIL) $(OPTIONS) -c Catalogue.cpp

ListTrajet.o: ListTrajet.cpp
	$(COMPIL) $(OPTIONS) -c ListTrajet.cpp

Element.o: Element.cpp
	$(COMPIL) $(OPTIONS) -c Element.cpp

TrajetSimple.o: TrajetSimple.cpp
	$(COMPIL) $(OPTIONS) -c TrajetSimple.cpp
	
Trajet.o: Trajet.cpp
	$(COMPIL) $(OPTIONS) -c Trajet.cpp

#Nettoyage
clean:
	rm -f *.o $(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)
