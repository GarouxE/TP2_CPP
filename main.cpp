//------------------------------------------------------ Include personnel
#include <iostream>
#include "Trajet.h"
#include "Element.h"
#include "TrajetSimple.h"
using namespace std;

int main() 
{
    Trajet trajet("A","B", SIMPLE);
    TrajetSimple trajetS("A", "B", AUTO);
    Element e(Trajet);

    printf("test1\n");
    e.Afficher();

    return 0;
}