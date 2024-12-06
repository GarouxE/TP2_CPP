/*************************************************************************
                           Element  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $2024$ par $AUTHOR$
    e-mail               : $anh-hung.ngo@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) ----------------
#if ! defined ( ELEMENT_H )
#define Element_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
//
//
//------------------------------------------------------------------------

class Element :
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
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

    Trajet *trajet;
    Element *eSuivant;
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif // ELEMENT_H

