//------------------------------------------------------ Include personnel
#include <iostream>
#include "Trajet.h"
#include "Element.h"
#include "TrajetSimple.h"
#include "ListeTrajet.h"
using namespace std;

int main() 
{
    Trajet trajet("A","B", SIMPLE);
    TrajetSimple trajetS("A", "B", AUTO);
    Element e(&trajet);
    ListeTrajet liste; //si mettre pas parametre -> pas parenthese
    liste.AjouterEnTete(&e);
    liste.Afficher();

    return 0;
}