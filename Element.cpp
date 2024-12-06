/*************************************************************************
                           Element  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $2024$ par $AUTHOR$
    e-mail               : $anh-hung.ngo@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Element.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Element::Afficher ( )
// Algorithme :
{
    cout << "Trajet : " << "\r\n";
    trajet->Afficher();
    if (eSuivant == NULL) cout << "Pas de trajet suivant" << "\r\n";
    else {
        cout << "Trajet suisant : " << "\r\n";
        eSuivant->trajet->Afficher();
    }

} //----- Fin de Méthode

Trajet *Element::GetTrajet ( )
// Algorithme :
{
    return trajet;
} //----- Fin de Méthode

Element *Element::GetElementSuivant ( )
// Algorithme :
{
    return eSuivant;
} //----- Fin de Méthode

void Element::SetElementSuivant ( Element *unElement )
// Algorithme :
{
    eSuivant = unElement;
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur

Element::Element (Trajet *unTrajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Element>" << endl;
#endif
    trajet = unTrajet;
    eSuivant = NULL;
} //----- Fin de Element


Element::~Element ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Element>" << endl;
#endif
    delete trajet;
} //----- Fin de ~Element


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

