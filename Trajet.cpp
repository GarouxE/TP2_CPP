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
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher ( )
{   
    if (type == COMPOSE) cout << "Trajet compose de " << depart << " a " << arrive << endl;
    else if (type == SIMPLE) cout << "Trajet simple de " << depart << " a " << arrive << endl;
} //----- Fin de Méthode

char * & Trajet::GetDepart ( ) {
    return depart;
} //----- Fin de Méthode

char * & Trajet::GetArrive ( ) {
    return arrive;
} //----- Fin de Méthode

TypeTrajet Trajet::GetType ( ) {
    return type;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet (const char *villeDep, const char *villeArr, TypeTrajet typeTrajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    depart = new char [strlen(villeDep) + 1];
    arrive = new char [strlen(villeArr) + 1];
    strcpy(depart, villeDep);
    strcpy(arrive, villeArr);
    type = typeTrajet;
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete [] depart;
    delete [] arrive;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
