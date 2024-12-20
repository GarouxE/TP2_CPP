/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher( );
    // Mode d'emploi : la fonction affiche le trajet compose (donc les trajets simples et les trajets composes qui le composent)
    //
    // Contrat : aucun
    //

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( ListeTrajet & trajetsListe, const char *villeDep, const char *villeArr );
    // Mode d'emploi : la fonction est un constructeur de TrajetCompose
    //
    // Contrat : villeDep et villeArr sont des villes différentes
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : la fonction est un destructeur de TrajetCompose
    //
    // Contrat : aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
ListeTrajet trajets;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
