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
#include <fstream>
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher ( ) const
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
      TrajetSimple * trajetS = dynamic_cast<TrajetSimple *>(trajet);
      cout << "Voyage " << i+1 << " : " << "TS" << ++s << " = ";
      trajetS->Afficher();
    } else {
      TrajetCompose * trajetC = dynamic_cast<TrajetCompose *>(trajet);
      cout << "Voyage " << i+1 << " : " << "TC" << ++c << " = ";
      trajetC->Afficher();
    }

    cout << endl;
    parcour = parcour-> GetElementSuivant();
  }
}


void Catalogue::RecherSimple ( const char *dep, const char *arr ) const
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

int Catalogue::Chargement(string & filename)
// Algorithme :
//
{
  ifstream fichier;
  fichier.open("./" + filename);

  if (fichier)
  {
    // int nb;
    // fichier >> nb;

    // for (int i = 0; i < nb; i++) 
    while (!fichier.eof()){
      string type;
      fichier >> type;

      if (type  == "S" || type == "s") {
        string depart, arrive;
        fichier >> depart >> arrive;

        int moyenTransport;
        fichier >> moyenTransport;

        ModeTransport mode = (ModeTransport) moyenTransport;
        Trajet * trajetS = new TrajetSimple(depart.c_str(), arrive.c_str(), mode);
        voyages->AjouterEnQueue(new Element(trajetS));
      }

      else if (type == "C" || type == "c") {
        int nbTrajets;
        fichier >> nbTrajets;

        ListeTrajet * trajetsListe = new ListeTrajet( );

        for (int num = 0; num < nbTrajets; num++) {
          string deb,fin;
          int moyenTransport;

          fichier >> deb >> fin >> moyenTransport;

          ModeTransport mode = (ModeTransport) moyenTransport;
          Trajet * trajet = new TrajetSimple(deb.c_str(), fin.c_str(), mode);
          trajetsListe->AjouterEnQueue(new Element(trajet));
        }
        Trajet * trajetC = new TrajetCompose(trajetsListe);
        voyages->AjouterEnQueue(new Element(trajetC));
      }

      else {
        //message d'erreur type non supporté
        cerr << "Type non supporté pour le catalogue" << endl;
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

int Catalogue::Sauvegarde(string & filename) 
// Algorithme :
//  
{
  ofstream fichier("./" + filename);

  if (fichier) {
    Element * parcour = voyages->GetTete();

    for (int i = 0; i < voyages->GetTaille(); ++i) {
      Trajet * unTrajet = parcour->GetTrajet();
      if (unTrajet->GetType() == SIMPLE) {
        TrajetSimple * unTrajetSimple = dynamic_cast<TrajetSimple*>(unTrajet);
        fichier << 'S' << ' ' << unTrajetSimple->GetDepart() << ' ' << unTrajetSimple->GetArrive() << ' ' << unTrajetSimple->GetMode() << endl;
      } else {
        TrajetCompose * unTrajetCompose = dynamic_cast<TrajetCompose*>(unTrajet);
        ListeTrajet * lesTrajets = unTrajetCompose->GetTrajets();
        int taille =  lesTrajets->GetTaille();
        fichier << 'C' << ' ' << taille;

        Element * parcour = lesTrajets->GetTete();
        for (int j = 0; j < taille; ++j) {
          Trajet * unTrajet = parcour->GetTrajet();
          TrajetSimple * unTrajetSimple = dynamic_cast<TrajetSimple*>(unTrajet);
          fichier << ' ' << unTrajetSimple->GetDepart() << ' ' << unTrajetSimple->GetArrive() << ' ' << unTrajetSimple->GetMode();
          
          parcour = parcour->GetElementSuivant();
        }
        fichier << endl;
      }
      parcour = parcour->GetElementSuivant();
    }
  } else {
    cerr << "ERREUR: Impossible d'ouvrir le fichier en ecriture." << endl;
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
