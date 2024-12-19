/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
//On a deux cas ici : 
//1. Trajet de Element est un TrajetSimple 
//2. Trajet de Element est un TrajetCompose
//Donc il faudra un "if" : parcour->trajet->type pour voir quel type qu'il est.
//S'il est du type TrajetSimple, on fait appel à la fonction Afficher du TrajetSimple.
//S'il est du type TrajetCompose, on fait appel à la fonction Afficher du TrajetCompose.
//Sachant que les deux fonctions ayant le même nom donc on ne va pas faire apparaitre les deux cas.
    Element* parcour = trajets.GetTete();

    for (int i = 0; i < trajets.GetTaille(); i++) {
        if (i) cout << " - ";
        parcour->GetTrajet()->Afficher();
        parcour = parcour->GetElementSuivant();
    }
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (ListeTrajet & trajetsListe, const char *villeDep, const char *villeArr):Trajet(villeDep,villeArr,COMPOSE)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    //verification des villes a faire _______________________________________________________________________________________________________________________________________
    //------------------------------------------
    //------------------------------------------
    //------------------------------------------
    //------------------------------------------
    //------------------------------------------
    //------------------------------------------
    trajets = trajetsListe;

} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
