/*************************************************************************
                          Catalogue  -  une classe de catalogue de trajets qui a pour but de 
                          manipuler et repésenter une liste de trajets
    début                : 21/11
    copyright            : (C) 2024 par Ewan GAROUX et Anh Hung NGO
    e-mail               : <ewan.garoux@insa-lyon.fr> ou <anh-hung.ngo@insa-lyon.fr>
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher ( )
// Algorithme :
//
{
  Element * parcour = voyages->GetTete();
  if (parcour == nullptr) {
    cout << "Catalogue vide.\r\n" << endl;
    return;
  }

  int taille = voyages->GetTaille();

  int s = 0, c = 0;
  for(int i = 0; i < taille; ++i)
  {
    Trajet * trajet = parcour->GetTrajet();
    if (trajet->GetType() == SIMPLE) {
      cout << "Voyage " << i+1 << " : " << "TS" << ++s << " = ";
    } else {
      cout << "Voyage " << i+1 << " : " << "TC" << ++c << " = ";
    }

    trajet->Afficher();
    cout << endl;
    parcour = parcour-> GetElementSuivant();
  }
}


void Catalogue::RecherSimple ( const char *dep, const char *arr ) 
// Algorithme :
//
{
  Element * parcour = voyages->GetTete();
  if (parcour == nullptr) {
    cout << "Catalogue vide.\r\n" << endl;
    return;
  }

  int taille = voyages->GetTaille();

  int s = 0, c = 0;
  for(int i = 0; i < taille; i++)
  {
    Trajet * trajet = parcour->GetTrajet();

    if (trajet->GetType() == SIMPLE) ++s;
    else ++c;

    if ( strcmp(trajet->GetDepart(), dep) == 0 && strcmp(trajet->GetArrive(), arr) == 0 ) {
      if (trajet->GetType() == SIMPLE) {
        cout<<"Voyage "<<i+1<<" : "<< "TS" << s << " = ";
      } else {
        cout<<"Voyage "<<i+1<<" : "<< "TC" << c << " = ";
      }

      trajet->Afficher();
      cout << endl;
      return;
    }
    parcour = parcour->GetElementSuivant();
  }  
  cout << "Aucun trajet trouve.\r\n" << endl;
  return;
}

ListeTrajet * & Catalogue::GetListeTrajet()
// Algorithme :
//
{
  return voyages;
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( ListeTrajet * trajetsListe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
  //voyages = trajetsListe; nguy hiểm vì mình không có hàm copy constructor -> nên dùng pointer
  voyages = trajetsListe;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
