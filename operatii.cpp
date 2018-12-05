//
// Created by DinuD-PC on 12/5/2018.
//

#include "operatii.h"
#include "structuri.h"
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;

ifstream fin("../date.in");
carte c[100];
persoana p[32];
sediu s[3];
int n, nrp;

void citire() {
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin.get();
        fin.get(c[i].titlu, 51);
        fin.get();
        fin.get(c[i].autor, 51);
        fin.get();
        fin.get(c[i].gen, 21);
        fin >> c[i].nr_pag >> c[i].rating >> c[i].stoc;
        fin >> c[i].nr_eliberate_curent >> c[i].nr_previous_chiriasi;
        fin >> c[i].id_carte;
    }
    fin >> nrp;
    for(int i = 0; i < nrp; i++) {
        fin.get();
        fin.get(p[i].nume, 31);
        fin.get();
        fin.get(p[i].prenume, 31);
        fin.get();
        fin.get(p[i].oras, 21);
        fin >> p[i].reputatie >> p[i].nr_carti;
        for(int j = 0; j < p[i].nr_carti; j++)
            fin >> p[i].id_carti_imprumutate[j];
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
        }
    } while(t != 0);
}