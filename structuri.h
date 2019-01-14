#ifndef LIBRARY_PROJECT_STRUCTURI_H
#define LIBRARY_PROJECT_STRUCTURI_H

struct carte {
    char titlu[51];
    char autor[51];
    char gen[21];
    int nr_pag;
    float rating;
    int stoc;
    int nr_eliberate_curent;
    int nr_previous_chiriasi;
    int id_carte;
};

struct persoana {
    char nume[31];
    char prenume[31];
    char oras[21];
    float reputatie;
    int nr_carti;
    int id_carti_imprumutate[50];
};

struct orar {
    int ora_deschidere;
    int ora_inchidere;
};

struct sediu {
    char strada[31];
    char oras[21];
    int nr;
    orar program;
};

#endif //LIBRARY_PROJECT_STRUCTURI_H
