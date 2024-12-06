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
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode




//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( ListeTrajet trajetsListe,const char *villeDep,const char *villeArr ):Trajet(villeDep, villeArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif

      trajets = trajetsListe;
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose (ListeTrajet trajetsListe,const char *villeDep,const char *villeArr):Trajet(villeDep,villeArr,COMPOSE)
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



void TrajetCompose::Afficher ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

      Element* parcour = trajets.GetTete();
      for(int i = 0; i < trajets.GetTaille(); i++)
      {
        if(i)cout << " - ";
        (parcour->GetTrajet())->Afficher();
        parcour = (*parcour).GetElementSuivant();
      }
} //----- Fin de ~TrajetCompose





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
