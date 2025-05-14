//
// Created by norik on 5/8/2025.
//

#ifndef BARAT_H
#define BARAT_H

typedef struct Datum {
    int ev;
    int honap;
    int nap;
} Datum;

typedef struct Barat{
    char nev[100];
    Datum szuletesiDatum;
    char nem;
    int bulizas;
}Barat;

#endif //BARAT_H
