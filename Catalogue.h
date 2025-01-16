/*************************************************************************
                          Catalogue  -  une classe de catalogue de trajets qui a pour but de
                          manipuler et repésenter une liste de trajets
                           -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H


#include <string>
#include <fstream>
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajet.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Le catalogue permet d'acceder a une liste de trajets.
//l permet aussi d'effectuer une recherche simple des trajets allant d'une ville A a B
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( );
    // Mode d'emploi : la fonction affiche la liste de trajets du catalogue
    //
    // Contrat :  aucun
    //

    void RecherSimple ( const char *dep, const char *arr );
    // Mode d'emploi :  la fonction recherche un trajet simple dans le catalogue
    //
    // Contrat :  dep et arr sont des villes différentes
    //

    ListeTrajet * & GetListeTrajet();
    // Mode d'emploi : la fonction retourne la liste de trajets du catalogue
    //
    // Contrat : aucun
    //

    int Chargement(string &name);
    // Mode d'emploi :  la fonction qui charge tous les trajets simples ou compose present dans le fichier passeer en entrée
    //
    // Contrat :  Le fichier doit avoir le  nombre de trajets à ajouter en 1ére ligne
    //            Si letrajet est simple il s'escrit      "S Ville_Depart Ville_Arrive Num_Moyen_Transport"
    //            Si letrajet est simple il s'escrit      "C Ville_Debut Ville_Fin Nb_Trajets" suivi de pour chage trajet "Ville_Depart Ville_Arrive Num_Moyen_Transport"


//-------------------------------------------- Constructeurs - destructeur
    Catalogue (ListeTrajet * trajetsListe );
    // Mode d'emploi : la fonction est un constructeur de Catalogue
    //
    // Contrat : aucun
    //

    virtual ~Catalogue ( );
    // Mode d'emploi : la fonction est un destructeur de Catalogue
    //
    // Contrat : aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  ListeTrajet * voyages;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
