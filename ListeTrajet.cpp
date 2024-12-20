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
        current->Afficher();
        current = current->GetElementSuivant();
    }
    cout << "\nTaille actuelle de la liste : " << taille << "\r\n";
} //----- Fin de Méthode

void ListeTrajet::AjouterEnQueue (Element * unElement)
{
    unElement->SetElementSuivant(nullptr);
    if (!taille) tete = unElement;
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
    ++taille;
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
    tete = nullptr;
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
    while (current != nullptr) {
        current = current->GetElementSuivant();
        delete current;
    }
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
