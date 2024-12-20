/*************************************************************************
                           ListeTrajet  -  description
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
//
//
//------------------------------------------------------------------------

class ListeTrajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterEnQueue (Element *unElement);

    Element *GetTete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetTaille ( );
    // Mode d'emploi :
    //
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
    Element *tete;
    int taille;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // LISTETRAJET_H
