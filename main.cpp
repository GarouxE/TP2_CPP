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

    //Créer un trajet composé qui contient que les trajets simples : 
    TrajetSimple trajetS1("A", "B", AUTO);
    TrajetSimple trajetS2("B", "C", BATEAU);
    Element eS1(&trajetS1);
    Element eS2(&trajetS2);
    ListeTrajet liste1;
    liste1.AjouterEnQueue(&eS1);
    liste1.AjouterEnQueue(&eS2);
    
    TrajetCompose trajetC1(liste1, "A", "C");
    Element eC1(&trajetC1);

    //Créer un trajet composé qui contient un trajet simple et un trajet composé : 
    ListeTrajet liste;
    liste.AjouterEnQueue(&eS);
    liste.AjouterEnQueue(&eC1);

    //Créer un trajet composé qui contient que les trajets simples et l'autre trajet composé : 
    TrajetCompose trajetC(liste, "D", "C");
    // trajetC.Afficher();

    Element eC(&trajetC);

    //Créer un catalogue :
    ListeTrajet listeC;
    listeC.AjouterEnQueue(&eS);
    listeC.AjouterEnQueue(&eC1);
    listeC.AjouterEnQueue(&eC);

    Catalogue cat(listeC);
    cat.Afficher();
    cat.RecherSimple("A", "C");

    return 0;
}

void menu() {
    cout << "1. Ajoute d'un trajet simple" << endl; //On peux juste faire une fonction ajoute d'un trajet ?
    cout << "2. Ajoute d'un trajet composé" << endl;
    cout << "3. Affichage du catalogue" << endl;
    cout << "4. Recherche simple d'un trajet" << endl;
    cout << "5. Recherche anvancée d'un trajet" << endl;
    cout << "6. Quitter" << endl;

    int choix;
    cin >> choix;

    switch (choix) {
    case 1:
        //Ajoute d'un trajet simple
        break;
    case 2:
        //Ajoute d'un trajet composé
        break;
    case 3:
        //Affichage du catalogue
        break;
    case 4:
        //Recherche simple d'un trajet
        break;
    case 5:
        //Recherche anvancée d'un trajet
        break;
    case 6:
        //Quitter
        break;
    default:
        cout << "Choix invalide" << endl;
        break;
    }
}
