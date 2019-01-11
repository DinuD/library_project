#include <iostream>
#include <conio.h>
#include <afxres.h>
#include "operatii.h"

using namespace std;

void meniu_user() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Afisare lista carti" << endl;
        cout << "2. Sortari" << endl;
        cout << "3. Cautari" << endl;
        cout << "4. Lista sediilor deschise in acest moment" << endl;
        cout << "5. Lista completa a sediilor" << endl;
        cout << "6. Imprumuta o carte" << endl;
        cout << "7. Returneaza o carte" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                afisare_carti();
            } getch(); break;

            case 2: {
                sortari_user();
            } break;

            case 3: {
                cautari();
            } break;

            case 4: {
                lista_sedii_deschise();
            } getch(); break;

            case 5: {
                lista_sedii();
            } getch(); break;

            case 6: {
                imprumut();
            } getch(); break;

            case 7: {
                returnare();
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

void meniu_admin() {
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Afisare lista clienti" << endl;
        cout << "2. Sortari" << endl;
        cout << "3. Cautari" << endl;
        cout << "4. Adaugare carte" << endl;
        cout << "5. Stergere carte" << endl;
        cout << "6. Actualizare stoc" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                afisare_clienti();
            } getch(); break;

            case 2: {
                sortari_admin();
            } break;

            case 3: {
                cautari_admin();
            } break;

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

int main() {
    citire();
    int t;
    do {
        system("cls");
        cout << "Selectati modul de log in" << endl;
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Client" << endl;
        cout << "2. Angajat/Administrator" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                meniu_user();
            } break;

            case 2: {
                meniu_admin();
            } break;

            case 0: {
                return 0;
            }

            default: {
                cout << "Optiune inexistenta. Incearca din nou\n";
                Sleep(1000);
            }
        }
    } while(t != 0);
    return 0;
}

// Dinu are multe subprograme