#Variables
COMPIL = g++
EDL = g++
OPTIONS = -ansi -pedantic -Wall -std=c++11

#Compilation du programme principal

trajets: main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o ListeTrajet.o Catalogue.o
	$(EDL) $(OPTIONS) -o trajets main.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o ListeTrajet.o 


#Compilation des fichiers source

main.o: main.cpp Catalogue.h
	$(COMPIL) $(OPTIONS) -c main.cpp

ListTrajet.o: ListTrajet.cpp ListTrajet.h Element.h
	$(COMPIL) $(OPTIONS) -c ListTrajet.cpp

Element.o: Element.cpp Element.h Trajet.h
	$(COMPIL) $(OPTIONS) -c Element.cpp

Catalogue.o: Catalogue.cpp Catalogue.h TrajetCompose.h
	$(COMPIL) $(OPTIONS) -c Catalogue.cpp

Trajet.o: Trajet.cpp Trajet.h
	$(COMPIL) $(OPTIONS) -c Trajet.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(COMPIL) $(OPTIONS) -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetSimple.h
	$(COMPIL) $(OPTIONS) -c TrajetCompose.cpp

#Nettoyage
clean:
	rm -f *.o $(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)
