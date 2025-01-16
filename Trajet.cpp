/*************************************************************************
                           Trajet  -  une classe qui permet de representer un trajet
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a afficher de <Trajet>" << endl;
#endif
    cout << "appel Trajet" << '\n';
} //----- Fin de Méthode

char * Trajet::GetDepart ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a GetDepart de <Trajet>" << endl;
#endif
    return nullptr;
} //----- Fin de Méthode

char * Trajet::GetArrive ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a GetArrive de <Trajet>" << endl;
#endif
    return nullptr;
} //----- Fin de Méthode


TypeTrajet Trajet::GetType ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a GetType de <Trajet>" << endl;
#endif
    return type;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet (TypeTrajet typeTrajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    type = typeTrajet;
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
