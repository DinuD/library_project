//
// Created by DinuD-PC on 12/5/2018.
//

#include "operatii.h"
#include "structuri.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <afxres.h>

using namespace std;

ifstream carti("../carti.in");
ifstream persoane("../persoane.in");
carte c[100];
persoana p[32];
sediu s[3];
int n, nrp;

void citire() {
    while(!carti.eof()) {
        carti.get(c[n].titlu, 51);
        carti.get();
        carti.get(c[n].autor, 51);
        carti.get();
        carti.get(c[n].gen, 21);
        carti >> c[n].nr_pag >> c[n].rating >> c[n].stoc;
        carti >> c[n].nr_eliberate_curent >> c[n].nr_previous_chiriasi;
        carti >> c[n].id_carte;
        carti.get();
        n++;
    }
    n--;
    while(!persoane.eof()) {
        persoane.get(p[nrp].nume, 31);
        persoane.get();
        persoane.get(p[nrp].prenume, 31);
        persoane.get();
        persoane.get(p[nrp].oras, 21);
        persoane >> p[nrp].reputatie >> p[nrp].nr_carti;
        for(int j = 0; j < p[nrp].nr_carti; j++)
            persoane >> p[nrp].id_carti_imprumutate[j];
        persoane.get();
        nrp++;
    }
}

void afisare_carti() {
    system("cls");
    for(int i = 0; i < n; i++) {
        cout << "Cartea #" << i+1 << ":" << endl;
        cout << "Titlu: " << c[i].titlu << endl;
        cout << "Autor: " << c[i].autor << endl;
        cout << "Gen: " << c[i].gen << endl;
        cout << "Numar pagini: " << c[i].nr_pag << endl;
        cout << "Rating: " << c[i].rating << "/5" << endl;
        cout << "In stoc: " << c[i].stoc << endl;
        cout << "Carti imprumutate in acest moment: " << c[i].nr_eliberate_curent << endl;
        cout << c[i].nr_previous_chiriasi << " persoane au imprumutat aceasta carte in trecut" << endl;
        cout << endl;
    }
}

void afisare_clienti() {
    system("cls");
    for(int i = 0; i < nrp; i++) {
        cout << "Nume: " << p[i].nume << endl;
        cout << "Prenume: " << p[i].prenume << endl;
        cout << "Oras: " << p[i].oras << endl;
        cout << "Reputatie: " << p[i].reputatie << endl;
        cout << endl;
    }
}

void afisari() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Afisare lista carti" << endl;
        cout << "2. Afisare lista clienti" << endl;
        cout << "0. Inapoi" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                afisare_carti();
            } getch(); break;

            case 2: {
                afisare_clienti();
            } getch(); break;

            case 0: {
                return;
            }

            default: {
                cout << "Optiune inexistenta. Incearca din nou\n";
                Sleep(1000);
            }
        }
    } while(t != 0);
}

void sortare_az_titlu() {
    int ok=1;
    carte aux;
    do {
        ok = 1;
        for(int i = 0; i < n-1; i++) {
            if(strcmp(c[i].titlu, c[i+1].titlu)>0) {
                aux = c[i];
                c[i] = c[i+1];
                c[i+1] = aux;
                ok = 0;
            }
        }
    } while(!ok);
    afisare_carti();
}

void sortare_az_autor() {
    int ok=1;
    carte aux;
    do {
        ok = 1;
        for(int i = 0; i < n-1; i++) {
            if(strcmp(c[i].autor, c[i+1].autor)>0) {
                aux = c[i];
                c[i] = c[i+1];
                c[i+1] = aux;
                ok = 0;
            }
        }
    } while(!ok);
    afisare_carti();
}

void sortare_desc_stoc() {
    int ok=1;
    carte aux;
    do {
        ok = 1;
        for(int i = 0; i < n-1; i++) {
            if(c[i].stoc < c[i+1].stoc) {
                aux = c[i];
                c[i] = c[i+1];
                c[i+1] = aux;
                ok = 0;
            }
        }
    } while(!ok);
    afisare_carti();
}

void sortare_az_clienti() {
    int ok=1;
    persoana aux;
    do {
        ok = 1;
        for(int i = 0; i < nrp-1; i++) {
            if(strcmp(p[i].nume, p[i+1].nume)>0) {
                aux = p[i];
                p[i] = p[i+1];
                p[i+1] = aux;
                ok = 0;
            } else if(strcmp(p[i].prenume, p[i+1].prenume)>0) {
                aux = p[i];
                p[i] = p[i+1];
                p[i+1] = aux;
                ok = 0;
            }
        }
    } while(!ok);
    afisare_clienti();
}

void sortare_desc_clienti_carti() {
    int ok=1;
    persoana aux;
    do {
        ok = 1;
        for(int i = 0; i < nrp-1; i++) {
            if(p[i].nr_carti < p[i+1].nr_carti) {
                aux = p[i];
                p[i] = p[i+1];
                p[i+1] = aux;
                ok = 0;
            }
        }
    } while(!ok);
    afisare_clienti();
}

void sortari() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Sortare carti alfabetic dupa titlu" << endl;
        cout << "2. Sortare carti alfabetic dupa autor" << endl;
        cout << "3. Sortare carti descrescator dupa stoc" << endl;
        cout << "4. Sortare carti descrescator dupa rating" << endl;
        cout << "5. Sortare lista clienti alfabetic" << endl;
        cout << "6. Sortare clienti descrescator in functie de numarul de carti imprumutate in prezent" << endl;
        cout << "0. Inapoi" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                sortare_az_titlu();
            } getch(); break;

            case 2: {
                sortare_az_autor();
            } getch(); break;

            case 3: {
                sortare_desc_stoc();
            } getch(); break;

            case 4: {
                sortare_az_clienti();
            } getch(); break;

            case 5: {
                sortare_desc_clienti_carti();
            } getch(); break;

            case 0: {
                return;
            }

            default: {
                return;
            }
        }
    } while(t != 0);
}

void cautare_carte() {

}

void cautari() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Cautare carte" << endl;
        cout << "2. Cautare carti in functie de autor" << endl;
        cout << "3. Cautare carti in functie de gen" << endl;
        cout << "0. Inapoi" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                sortare_az_titlu();
            } getch(); break;

            case 2: {
                sortare_az_autor();
            } getch(); break;

            case 3: {
                sortare_desc_stoc();
            } getch(); break;

            case 4: {
                sortare_az_clienti();
            } getch(); break;

            case 5: {
                sortare_desc_clienti_carti();
            } getch(); break;

            case 0: {
                return;
            }

            default: {
                return;
            }
        }
    } while(t != 0);
}