/*************************************************************************
                           TrajetSimple - une classe qui permet de representer un trajet simple
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes
const char* Transport[] = { "BATEAU", "AUTO", "TRAIN", "AVION"};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher ()
// Algorithme : aficher le trajet simple (donc le depart, l'arrivee et le moyen de transport)
//
{
#ifdef MAP
    cout << "Appel a afficher de <TrajetSimple>" << endl;
#endif
    cout << "de "<< depart << " a "<< arrive<< " en "<< Transport[(int)mode];
}

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char *villeDep, const char *villeArr, ModeTransport modeTransport):Trajet(villeDep, villeArr,SIMPLE)
// Algorithme : initialiser le trajet simple avec le depart, l'arrivee et le moyen de transport
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    mode = modeTransport;

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple()
// Algorithme : detruire le trajet simple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
