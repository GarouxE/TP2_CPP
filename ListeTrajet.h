/*************************************************************************
                           ListeTrajet  -  une classe qui permet de construire une liste chainée et de manipuler ses elements
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ----------------
#if ! defined ( LISTETRAJET_H )
#define LISTETRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajet>
//C'est une classe permettant de construire une liste chainée et de manipuler ses elements.
//
//------------------------------------------------------------------------

class ListeTrajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( );
    // Mode d'emploi :
    //Affiche tous les elements de la liste chainée.
    // Contrat :
    //

    void AjouterEnQueue (Element * unElement);
    // Mode d'emploi :
    // Permet d'ajoute un element en fin de la liste chainée.
    // Contrat :
    //

    Element * & GetTete ( );
    // Mode d'emploi :
    //Renvoie l'element en tet de la liste chainée.
    // Contrat :
    //

    int GetTaille ( );
    // Mode d'emploi :
    //Renvoi le nombre d'element dans la liste chainée.
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    ListeTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Element * tete;
    int taille;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // LISTETRAJET_H
