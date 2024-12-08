#include <iostream>
#include "Trajet.h"
#include "Element.h"
#include "TrajetSimple.h"
#include "ListeTrajet.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

using namespace std;

int main()
{
    Trajet trajet("a","b", SIMPLE);
    TrajetSimple trajetS("a", "b", AUTO);
    TrajetSimple trajetB("b", "d", AUTO);

    Element e(&trajetS);
    Element e2(&trajetB);
    ListeTrajet Liste;

    Liste.AjouterEnTete(&e2);
    Liste.AjouterEnTete(&e);

    TrajetCompose TrajetDur(Liste,"a","d");

    Element e3(&TrajetDur);

    ListeTrajet Liste2;
    Liste2.AjouterEnTete(&e2);
    Liste2.AjouterEnTete(&e);
    Liste2.AjouterEnTete(&e3);

    Catalogue catalogue(Liste2);


    printf("test pour Element\n");
    e.Afficher();
    printf("\n\n");

    printf("test pour TrajetSimple\n");
    trajetS.Afficher();
    printf("\n\n");

    printf("test pour TrajetCompose\n");
    TrajetDur.Afficher();
    printf("\n\n");

    printf("test pour Catalogue\n");
    catalogue.Afficher();
    printf("\n\n");

    return 0;
}
