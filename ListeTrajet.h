/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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

    void AjouterEnTete (Element *unElement);
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
