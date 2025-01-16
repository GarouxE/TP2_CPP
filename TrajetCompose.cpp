/*************************************************************************
                            TrajetCompose  -  une classe qui permet de representer un trajet compose
                            donc un trajet qui est compose de plusieurs trajets simples et composes
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
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
// Algorithme : utiliser un parcour pour parcourir la liste de trajets et afficher chaque trajet
//S'il est du type TrajetSimple, on fait appel à la fonction Afficher du TrajetSimple.
//S'il est du type TrajetCompose, on fait appel à la fonction Afficher du TrajetCompose.
//Sachant que les deux fonctions ayant le même nom donc on ne va pas faire apparaitre les deux cas.
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    Element * parcour = trajets->GetTete();

    for (int i = 0; i < 2; i++){
        if (i) cout << " - ";
        parcour->GetTrajet()->Afficher();
        parcour = parcour->GetElementSuivant();
    }
} //----- Fin de Méthode

char * TrajetCompose::GetDepart ( ) {
    return trajets->GetTete()->GetTrajet()->GetDepart();
} //----- Fin de Méthode

char * TrajetCompose::GetArrive ( ) {
    return trajets->GetQueue()->GetTrajet()->GetArrive();
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (ListeTrajet * trajetsListe):Trajet(COMPOSE)
// Algorithme : initialiser le trajet compose avec la liste de trajets simples et composes qui le composent
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    trajets = trajetsListe;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme : detruire le trajet compose
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete trajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
