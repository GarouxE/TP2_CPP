/*************************************************************************
                           Element  -  une classe qui permet de representer un element d'une liste chainee
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) ----------------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
//
//
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( );
    // Mode d'emploi : affiche le trajet
    //
    // Contrat : aucun
    //

    Trajet * GetTrajet ( );
    // Mode d'emploi : retourne le trajet
    //
    // Contrat : aucun
    //

    Element * GetElementSuivant ( );
    // Mode d'emploi : prend un element suivant
    //
    // Contrat : aucun
    //

    void SetElementSuivant ( );
    // Mode d'emploi : rajouter un element null
    //
    // Contrat : aucun
    //

    void SetElementSuivant ( Element * unElement );
    // Mode d'emploi : rajouter un element
    //
    // Contrat : aucun
    //

//-------------------------------------------- Constructeurs - destructeur
    Element (Trajet *unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Element ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Trajet *trajet;
    Element *eSuivant;
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif // ELEMENT_H
