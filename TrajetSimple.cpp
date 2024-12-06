/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode




//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char *villeDep, const char *villeArr, ModeTransport modeTransport):Trajet(villeDep, villeArr,SIMPLE)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    mode = modeTransport;

} //----- Fin de TrajetSimple



void TrajetSimple::Afficher ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a afficher de <TrajetSimple>" << endl;
#endif
    cout << "de "<< depart << " à "<< arrive<< " en "<< Transport[(int)mode]<< endl;

}




TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
