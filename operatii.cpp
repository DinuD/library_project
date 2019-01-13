//
// Created by DinuD-PC on 12/5/2018.
//

#include "operatii.h"
#include "structuri.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <afxres.h>
#include <ctime>

using namespace std;

ifstream carti("../carti.in");
ifstream persoane("../persoane.in");
ifstream sedii("../sedii.in");
ifstream intro("../intro.in");
carte c[100];
persoana p[32];
sediu s[5];
int n, nrp, nrs;

void citire() {
    char linie[51];
    cout << "\n\n\n\n\n\n";
    while(!intro.eof()) {
        intro.get(linie, 51);
        intro.get();
        cout << "\t\t\t\t\t" << linie << endl;
        Sleep(300);
    }
    Sleep(1000);
    while(!carti.eof()) {
        carti.get(c[n].titlu, 51);
        carti.get();
        carti.get(c[n].autor, 51);
        carti.get();
        carti.get(c[n].gen, 21);
        carti >> c[n].nr_pag >> c[n].rating >> c[n].stoc;
        carti >> c[n].nr_eliberate_curent >> c[n].nr_previous_chiriasi;
        carti.get();
        n++;
    }
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
    while(!sedii.eof()) {
        sedii.get(s[nrs].strada, 31);
        sedii.get();
        sedii.get(s[nrs].oras, 21);
        sedii >> s[nrs].nr >> s[nrs].program.ora_deschidere;
        sedii >> s[nrs].program.ora_inchidere;
        sedii.get();
        nrs++;
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
}

void sortare_desc_rating() {
    int ok=1;
    carte aux;
    do {
        ok = 1;
        for(int i = 0; i < n-1; i++) {
            if(c[i].rating < c[i+1].rating) {
                aux = c[i];
                c[i] = c[i+1];
                c[i+1] = aux;
                ok = 0;
            }
        }
    } while(!ok);
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
            } else if(strcmp(p[i].nume, p[i+1].nume)==0)
                if(strcmp(p[i].prenume, p[i+1].prenume)>0) {
                    aux = p[i];
                    p[i] = p[i+1];
                    p[i+1] = aux;
                    ok = 0;
                }
        }
    } while(!ok);
}

void sortare_clienti_reputatie() {
    int ok = 1, i, j;
    persoana aux;
    for (i = 0; i < nrp - 1; i++) {
        for (j = i + 1; j < nrp; j++) {
            if (p[i].reputatie < p[i + 1].reputatie) {
                aux = p[i];
                p[i] = p[i + 1];
                p[i + 1] = aux;
            }
        }
    }
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
}

void sortari_user() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Sortare carti alfabetic dupa titlu" << endl;
        cout << "2. Sortare carti alfabetic dupa autor" << endl;
        cout << "3. Sortare carti descrescator dupa stoc" << endl;
        cout << "4. Sortare carti descrescator dupa rating" << endl;
        cout << "0. Inapoi" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                sortare_az_titlu();
				afisare_carti();
            } getch(); break;

            case 2: {
                sortare_az_autor();
				afisare_carti();
            } getch(); break;

            case 3: {
                sortare_desc_stoc();
				afisare_carti();
            } getch(); break;

            case 4: {
                sortare_desc_rating();
                afisare_carti();
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

void sortari_admin() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Sortare lista clienti alfabetic" << endl;
        cout << "2. Sortare clienti dupa rating" << endl;
        cout << "3. Sortare clienti descrescator in functie de numarul de carti imprumutate" << endl;
        cout << "0. Inapoi" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                sortare_az_clienti();
                afisare_clienti();
            } getch(); break;

            case 2: {
                sortare_clienti_reputatie();
                afisare_clienti();
            } getch(); break;

            case 3: {
                sortare_desc_clienti_carti();
                afisare_clienti();
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

void afisare_carte(int i) {
    cout << "Cod Carte: " << i+1 << endl;
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

void cautare_carte() {
	system("cls");
	char s[51];
	sortare_az_titlu();
	cout << "Ce carte cauti?" << endl;
    cin.get();
	cin.get(s, 51);
	int st=0, dr=n-1, m;
	do {
		m = (st+dr)/2;
		if(strcasecmp(c[m].titlu, s)==0) {
			afisare_carte(m);
			return;
		} else if(strcasecmp(s, c[m].titlu)<0)
			dr = m-1;
		else
			st = m+1;
	} while(st<=dr);
	cout << "Nu am gasit cartea. Incearca din nou" << endl;
}

void cautare_dupa_autor() {
    system("cls");
    char s[51];
    int ok = 1;
    cout << "Ce autor cauti?" << endl;
    cin.get();
    cin.get(s, 51);
    sortare_az_autor();
    for(int i = 0; i < n; i++) {
        if(strcasecmp(s, c[i].autor)==0) {
            if(ok)
                cout << "Cartile lui " << c[i].autor << ":\n";
            ok = 0;
            afisare_carte(i);
        }
    }
    if(ok)
        cout << "Nu am gasit acest autor" << endl;
}

void cautare_dupa_gen() {
    system("cls");
    char s[21];
    int ok = 1;
    cout << "Ce gen cauti?" << endl;
    cin.get();
    cin.get(s, 21);
    for(int i = 0; i < n; i++) {
        if(strcasecmp(s, c[i].gen)==0) {
            if(ok)
                cout << "Cartile " << c[i].gen << ":\n";
            ok = 0;
            afisare_carte(i);
        }
    }
    if(ok)
        cout << "Nu am gasit acest gen";
}

void afisare_client(int i){
    cout << "Nume: " << p[i].nume << endl;
    cout << "Prenume: " << p[i].prenume << endl;
    cout << "Oras: " << p[i].oras << endl;
    cout << "Reputatie: " << p[i].reputatie << endl;
    cout << endl;
}

void cautare_client(){
    system("cls");
    char s[31],s1[31];
    sortare_az_clienti();
    cout<<"Nume persoana cautata: "<<endl;
    cin.get();
    cin.get(s,31);
    cout<<"Prenume persoana cautata: "<<endl;
    cin.get();
    cin.get(s1,31);
    int st=0, dr=nrp-1, m;
    do{
        m = (st+dr)/2;
        if(strcasecmp(p[m].nume, s)==0) {
            if(strcasecmp(p[m].prenume, s1)==0)
                afisare_client(m);
                return;
        } else if(strcasecmp(s, p[m].nume)<0)
                dr = m-1;
        else
            st = m+1;
    }while(st<=dr);
    cout << "Nu am gasit persoana. Incearca din nou" << endl;
}

void cautare_client_oras(){
    system("cls");
    char s[21];
    sortare_az_clienti();
    cout<<"Introdu orasul: "<<endl;
    cin.get();
    cin.get(s, 21);
    int i,nr=0;
    for(i=0;i<nrp;i++)
        if(strcasecmp(p[i].oras,s)==0){
            afisare_client(i);
            nr=1;
        }
    if(nr==0)
        cout<<"Nu exista clienti in orasul cautat";
    cout<<endl;
}

void cautari_user() {
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
                cautare_carte();
            } getch(); break;

            case 2: {
                cautare_dupa_autor();
            } getch(); break;

            case 3: {
                cautare_dupa_gen();
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

void cautari_admin() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Cautare persoana" << endl;
        cout << "2. Cautare persoana in functie de oras" << endl;
        cout << "0. Inapoi" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                cautare_client();
            } getch(); break;

            case 2: {
                cautare_client_oras();
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

void lista_sedii_deschise() {
    system("cls");
    cout << "Lista sedii deschise in acest moment:\n\n";
    time_t now = time(0);
    tm *ltm = localtime(&now);
//    cout << ltm->tm_hour << ":" << ltm->tm_min;
    for(int i = 0; i < nrs; i++) {
        if(ltm->tm_hour >= s[i].program.ora_deschidere &&
                ltm->tm_hour < s[i].program.ora_inchidere)
        {
            cout << s[i].strada << " " << s[i].nr << endl;
            cout << s[i].oras << endl;
            cout << "Orar: " << s[i].program.ora_deschidere << "-" << s[i].program.ora_inchidere;
            cout << endl << endl;
        }
    }
}

void lista_sedii() {
    system("cls");
    for(int i = 0; i < nrs; i++) {
        cout << i+1 << ".\n";
        cout << s[i].strada << " " << s[i].nr << endl;
        cout << s[i].oras << endl;
        cout << "Orar: " << s[i].program.ora_deschidere << "-" << s[i].program.ora_inchidere;
        cout << endl;
    }
}

void imprumut() {
    system("cls");
    int cod;
    cout << "Introdu codul cartii dorite:" << endl;
    cin >> cod;
    cod--;
    c[cod].nr_eliberate_curent++;
    c[cod].nr_previous_chiriasi++;
    cout << "Ai imprumutat cartea " << c[cod].titlu << " de " << c[cod].autor << endl;
}

void returnare() {
    system("cls");
    int cod;
    cout << "Introdu codul cartii pe care o returnezi:" << endl;
    cin >> cod;
    cod--;
    c[cod].nr_eliberate_curent--;
    cout << "Ai returnat cartea " << c[cod].titlu << " de " << c[cod].autor << endl;
}

void adaugare_carte(){
    system("cls");
    cout<<"Date carte: "<<endl;
    cout << "Titlu: ";
    cin.get();
    cin.get(c[n].titlu,51);
    cout << "Autor: ";
    cin.get();
    cin.get(c[n].autor,51);
    cout << "Gen: ";
    cin.get();
    cin.get(c[n].gen,21);
    cout << "Numar pagini: ";
    cin>>c[n].nr_pag;
    cout << "Rating: ";
    cin>>c[n].rating;
    cout << "In stoc: ";
    cin>>c[n].stoc;
    n++;
}

void stergere_carte(){
    system("cls");
    int i, x;
    carte s;
    cout<<"Introdu codul cartii dorite:"<<endl;
    cin >> x;
    if(x-1>n-1) {
        cout << "Cartea pe care doriti sa o stergeti nu exista.";
        return;
    }
    cout << "Ai sters cartea " << c[x-1].titlu << " de " << c[x-1].autor << endl;
    for(i=x-1;i<n;i++) {
        c[i] = c[i+1];
    }
    n--;
}

void actualizare_stoc(){
    system("cls");
    carte k;
    int x;
    int nr;
    cout<<"Codul cartii ce necesita aclualizare: "<<endl;
    cin >> x;
    x--;
    cout << "Ai selectat cartea " << c[x].titlu << " de " << c[x].autor << endl;
    cout<<"Numarul adaugat/scazut de exemplare: \n";
    cin>>nr;
    c[x].stoc = c[x].stoc+nr;
}