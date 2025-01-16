/*************************************************************************
                           Element  -  une classe qui permet de representer un element d'une liste chainee
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
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
    cout << "Trajet : ";
    trajet->Afficher();
    cout << "\nTrajet suivant : ";
    if (eSuivant == NULL) cout << "Pas de trajet suivant" << "\r\n";
    else {
        eSuivant->trajet->Afficher();
    }

} //----- Fin de Méthode

Trajet * Element::GetTrajet ( )
// Algorithme :
{
    return trajet;
} //----- Fin de Méthode

Element * Element::GetElementSuivant ( )
// Algorithme :
{
    return eSuivant;
} //----- Fin de Méthode

void Element::SetElementSuivant ( )
// Algorithme :
{
    eSuivant = nullptr;
} //----- Fin de Méthode

void Element::SetElementSuivant ( Element * unElement )
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
    eSuivant = nullptr;
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
