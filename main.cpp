#include <iostream>
#include "operatii.h"

using namespace std;

int main() {
    citire();
    int t;
    do {
        system("cls");
        cout << "Introdu numarul optiunii dorite si apasa Enter!" << endl;
        cout << "1. Afisari" << endl;
        cout << "2. Sortari" << endl;
        cout << "3. Cautari" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiunea dorita: ";
        cin >> t;
        switch(t) {
            case 1: {
                afisari();
            } break;

            case 0: {
                return 0;
            }
        }
    } while(t != 0);
    return 0;
}