#include <iostream>
#include "Trajet.h"
#include "TrajetCompose.h"
#include "Element.h"
#include "TrajetSimple.h"
#include "ListeTrajet.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

using namespace std;

int main()
{
    //Créer un trajet simple :
    TrajetSimple trajetS("D", "A", AVION);
    Element eS(&trajetS);

    //Créer un trajet composé qui contient que les trajets simples: 
    TrajetSimple trajetS1("A", "B", AUTO);
    TrajetSimple trajetS2("B", "C", BATEAU);
    Element eS1(&trajetS1);
    Element eS2(&trajetS2);
    ListeTrajet liste1;
    liste1.AjouterEnTete(&eS1);
    liste1.AjouterEnTete(&eS2);
    
    TrajetCompose trajetC1(liste1, "A", "C");
    Element eC1(&trajetC1);

    //Créer un trajet composé qui contient un trajet simple et un trajet composé: 
    ListeTrajet liste;
    liste.AjouterEnTete(&eS);
    liste.AjouterEnTete(&eC1);

    TrajetCompose trajetC(liste, "D", "C");
    trajetC.Afficher();

    return 0;
}
