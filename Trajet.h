/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
    
    char *GetDepart ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    char *GetArrive ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    TypeTrajet GetType ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet (const char *villeDep, const char *villeArr, TypeTrajet typeTrajet);
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
    char *depart;
    char *arrive;
    TypeTrajet type;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
