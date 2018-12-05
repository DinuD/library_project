//
// Created by DinuD-PC on 12/5/2018.
//

#include "operatii.h"
#include "structuri.h"
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("../date.in");
carte c[100];
persoana p[32];
sediu s[3];

void citire() {
    int n;
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
}