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


int Catalogue::Chargement(string &name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

  ifstream fic;
  fic.open("./"+name);

  if(fic)
  {
    int nb;
    fic >> nb;

    for (int i = 0; i < nb; i++) {
      string type;
      fic >> type;

      if (type  == "S" || type == "s") {
        string depart, arrive;
        fic >> depart >> arrive;

        int moyenTransport;
        fic >> moyenTransport;

        ModeTransport mode = (ModeTransport)moyenTransport;
        Trajet * trajet = new TrajetSimple(depart.c_str(), arrive.c_str(), mode);
        voyages -> AjouterEnQueue(new Element(trajet));
      }

      else if (type == "C" || type == "c") {
        int nbTrajets;
        fic >> nbTrajets;

        ListeTrajet * trajetsListe = new ListeTrajet( );

        for(int num = 0; num < nbTrajets; num++) {
          string deb,fin;
          int moyenTransport;

          fic >> deb >> fin >> moyenTransport;

          ModeTransport mode = (ModeTransport) moyenTransport;
          Trajet * trajet = new TrajetSimple(deb.c_str(), fin.c_str(), mode);
          trajetsListe -> AjouterEnQueue(new Element(trajet));
        }
        Trajet * trajet = new TrajetCompose(trajetsListe);
        voyages -> AjouterEnQueue(new Element(trajet));
      }

      else {
        //message d'erreur type non supporté
        cerr << "Type non supporté pour le catalogue"<<endl;
        return 0;
      }
    }
 }
 else {
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    return 0;
 }
 return 1;
}


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( ListeTrajet * trajetsListe )
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
  delete voyages;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
