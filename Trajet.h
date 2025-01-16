/*************************************************************************
                           Trajet  -  une classe qui permet de representer un trajet
                             -------------------
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum TypeTrajet
{
  SIMPLE,
  COMPOSE
};
//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual char * GetDepart ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * GetArrive ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    TypeTrajet GetType ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet (TypeTrajet typeTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TypeTrajet type;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
