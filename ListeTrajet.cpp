/*************************************************************************
                           ListeTrajet  -  une classe qui permet de construire une liste chainée et de manipuler ses elements
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"
#include "Element.h"
//------------------------------------------------------------- Constantes
 
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ListeTrajet::Afficher( ) {
    Element *current = tete;
    while (current != nullptr) {
        current-> GetTrajet() ->Afficher();
        current = current-> GetElementSuivant();
    }
    cout << "\nTaille actuelle de la liste : " << GetTaille() << "\r\n";
} //----- Fin de Méthode

void ListeTrajet::AjouterEnQueue (Element * unElement)
{
    unElement->SetElementSuivant();
    if (!GetTaille()) {
      tete = unElement;
      }
    else {
        Element * parcour = tete;
        while (1) {
            if (parcour->GetElementSuivant() == nullptr) {
                parcour->SetElementSuivant(unElement);
                break;
            }
            parcour = parcour->GetElementSuivant();
        }
    }
} //----- Fin de Méthode

Element * ListeTrajet::GetTete ( )
{
    return tete;
} //----- Fin de Méthode

Element * ListeTrajet::GetQueue ( )
{
    Element * parcour = tete;
    while (parcour->GetElementSuivant() != nullptr) {
        parcour = parcour->GetElementSuivant();
    }
    return parcour;
} //----- Fin de Méthode

int ListeTrajet::GetTaille ( )
{
  if (tete == nullptr) return 0;
  int taille = 0;
  Element * parcour = tete;
  while (parcour != nullptr)
  {
    parcour = parcour->GetElementSuivant();
    ++taille;
  }
  return taille;

} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur

ListeTrajet::ListeTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif
    tete = nullptr;
} //----- Fin de ListeTrajet


ListeTrajet::~ListeTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
    Element *current = tete;
    while (current != nullptr) {
        Element *tmps = current;
        current = current->GetElementSuivant();
        if(tmps != nullptr) delete tmps;
    }
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
