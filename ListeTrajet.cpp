/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $2024$ par $AUTHOR$
    e-mail               : $anh-hung.ngo@insa-lyon.fr$
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
    while (current != NULL) {
        current->Afficher();
        current = current->GetElementSuivant();
    }
    cout << "Taille de la liste" << taille << "\r\n";
} //----- Fin de Méthode

void ListeTrajet::AjouterEnTete (Element *unElement)
{
    unElement->SetElementSuivant(tete);
    tete = unElement;
    taille++;
} //----- Fin de Méthode

Element * ListeTrajet::GetTete ( )
{
    return tete;
} //----- Fin de Méthode

int ListeTrajet::GetTaille ( )
{
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
    tete = NULL;
    taille = 0;
} //----- Fin de ListeTrajet


ListeTrajet::~ListeTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
    Element *current = tete;
    while (current != NULL) {
        current = current->GetElementSuivant();
        delete current;
    }
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

