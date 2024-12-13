/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
  Element* parcour = voyages.GetTete();
  int taille = voyages.GetTaille();

  int s = 0, c = 0;
  for(int i = 0; i < taille; i++)
  {
    Trajet * trajet = parcour->GetTrajet();
    if (trajet->GetType() == SIMPLE) { //je modifie ici pour qu'il affiche comme l'exemple
      cout<<"Voyage "<<i+1<<" : "<< "TS" << ++s << " = ";
    } else {
      cout<<"Voyage "<<i+1<<" : "<< "TC" << ++c << " = ";
    }

    trajet->Afficher();
    cout<<" "<<endl;
    parcour = parcour-> GetElementSuivant();
  }
}


void Catalogue::RecherSimple ( const char *dep, const char *arr ) 
// Algorithme :
//
{
  Element* parcour = voyages.GetTete();
  int taille = voyages.GetTaille();

  int s = 0, c = 0;
  for(int i = 0; i < taille; i++)
  {
    Trajet * trajet = parcour->GetTrajet();

    int type;
    if (trajet->GetType() == SIMPLE) {
      type = 1;
      ++s;
    } else {
      type = 0;
      ++c;
    }
    
    if ( (strcmp(trajet->GetDepart(), dep) == 0) && (strcmp(trajet->GetArrive(), arr) == 0) ) {
      if (type) {
        cout<<"Voyage "<<i+1<<" : "<< "TS" << s << " = ";
      } else {
        cout<<"Voyage "<<i+1<<" : "<< "TC" << c << " = ";
      }

      trajet->Afficher();
      cout<<" "<<endl;
    }
    parcour = parcour-> GetElementSuivant();
  }  
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( ListeTrajet & trajetsListe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
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
