/*************************************************************************
                           Menu  -  main
                             -------------------
    début                : //2024
    copyright            : (C) 
    e-mail               : $EMAIL$
*************************************************************************/

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include <iostream>
#include "Trajet.h"
#include "TrajetCompose.h"
#include "Element.h"
#include "TrajetSimple.h"
#include "ListeTrajet.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

using namespace std;


int main() {
    ListeTrajet uneListe;
    Catalogue catalogue(uneListe);

    while(true)
    {
        cout << "Menu :" << endl;
        cout << "1. Affichage du catalogue" << endl;
        cout << "2. Ajouter trajet simple" << endl;
        cout << "3. Ajouter trajet compose" << endl;
        cout << "4. Recherche simple" << endl;
        cout << "5. Quitter" << endl;

        int n;
        cin >> n;

        switch (n)
        {
            case 1:
                catalogue.Afficher();
                break;

            case 2:
            {
                cout << "Depart :" << endl;
                char depart[100];
                cin >> depart;

                cout << "Arrivee :" << endl;
                char arrivee[100];
                cin >> arrivee;

                if (strcmp(depart,arrivee) == 0) {
                    cerr << "Le depart et l'arrivee doivent etre differents" << endl;
                    break;
                }

                cout << "Nom du moyen de transport : ";
                int choixDeTransport;
                cin >> choixDeTransport;
                ModeTransport mode = (ModeTransport)choixDeTransport;

                Trajet * trajet = new TrajetSimple(depart, arrivee, mode);
                catalogue.GetListeTrajet().AjouterEnQueue(new Element(trajet));
                break;
            }
            case 3:
            {
                cout << "Depart :" << endl;
                char depart[100];
                cin >> depart;

                cout << "Arrivee :" << endl;
                char arrivee[100];
                cin >> arrivee;

                if (strcmp(depart,arrivee) == 0) {
                    cerr << "Le depart et l'arrivee doivent etre differents" << endl;
                    break;
                }

                ListeTrajet trajetsListe;
                cout << "Combien de trajets simples ?" << endl;
                int nbTrajets;
                cin >> nbTrajets;

                char *tmp = new char [100];
                strcpy(tmp, depart);

                for (int i = 0; i < nbTrajets; ++i)
                {
                    cout << "Depart :" << endl;
                    char departS[100];
                    cin >> departS;

                    if (strcmp(tmp,departS)) {
                        cerr << "Le depart n'est pas valide" << endl;
                        break;
                    }

                    cout << "Arrivee :" << endl;
                    char arriveeS[100];
                    cin >> arriveeS;

                    if (i + 1 == nbTrajets && strcmp(arrivee,arriveeS)) {
                        cerr << "L'arrivee n'est pas valide" << endl;
                        break;
                    }

                    if (strcmp(departS, arriveeS) == 0) {
                        cerr << "Le depart et l'arrivee doivent etre differents" << endl;
                        break;
                    }

                    strcpy(tmp, arriveeS);

                    cout << "Nom du moyen de transport : ";
                    int choixDeTransport;
                    cin >> choixDeTransport;
                    ModeTransport mode = (ModeTransport)choixDeTransport;

                    Trajet * trajet = new TrajetSimple(departS, arriveeS, mode);
                    trajetsListe.AjouterEnQueue(new Element(trajet));
                }

                Trajet * trajet = new TrajetCompose(trajetsListe, depart, arrivee);
                catalogue.GetListeTrajet().AjouterEnQueue(new Element(trajet));
                break;
            }
            case 4:
            {
                cout << "Depart :" << endl;
                char depart[100];
                cin >> depart;

                cout << "Arrivee :" << endl;
                char arrivee[100];
                cin >> arrivee;

                while (strcmp(depart,arrivee) == 0)
                {
                    cerr << "Le depart et l'arrivee doivent etre differents" << endl;
                    cout << "Arrivee :" << endl;
                    cin >> arrivee;
                }

                catalogue.RecherSimple(depart, arrivee);
                break;
            }
            case 5:
                return 0;
        }
    }

    return 0;
}