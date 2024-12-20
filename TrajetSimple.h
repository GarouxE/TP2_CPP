/*************************************************************************
                           TrajetSimple  -  une classe qui permet de representer un trajet simple
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum ModeTransport
{
  BATEAU,
  AUTO,
  TRAIN,
  AVION
};
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher();
    // Mode d'emploi : la fonction affiche le trajet simple (donc le depart, l'arrivee et le moyen de transport)
    //
    // Contrat : aucun
    //

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple (const char *villeDep, const char *villeArr, ModeTransport modeTransport);
    // Mode d'emploi : la fonction est un constructeur de TrajetSimple
    //
    // Contrat : villeDep et villeArr sont des villes différentes
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi : la fonction est un destructeur de TrajetSimple
    //
    // Contrat : aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    ModeTransport mode;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
