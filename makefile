main: main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o ListeTrajet.o Catalogue.o
	g++ -o main main.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o ListeTrajet.o 

main.o: main.cpp
	g++ -c main.cpp

Catalogue.o: Catalogue.cpp
	g++ -c Catalogue.cpp

Trajet.o: Trajet.cpp
	g++ -c Trajet.cpp

TrajetSimple.o: TrajetSimple.cpp
	g++ -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp
	g++ -c TrajetCompose.cpp

Element.o: Element.cpp
	g++ -c Element.cpp

ListeTrajet.o: ListeTrajet.cpp
	g++ -c ListeTrajet.cpp