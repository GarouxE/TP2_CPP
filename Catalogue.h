/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Le catalogue permet d'acceder a une liste de trajets.
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( );
    // Mode d'emploi :
    // La methode affiche les differents trajets possibles.
    // Contrat :
    // --

    void RecherSimple ( const char *dep, const char *arr );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ListeTrajet & GetListeTrajet();
    // Mode d'emploi :
    //Permet d'obtenir la Liste des Trajets du catalogue 
    // Contrat :
    //--

//-------------------------------------------- Constructeurs - destructeur
    Catalogue (ListeTrajet & trajetsListe );
    // Mode d'emploi :
    // Creer un catalogue a partie d'une liste de trajets
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Destructeur de catalogue
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  int taille;
  ListeTrajet voyages;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
