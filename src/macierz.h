#ifndef _MACIERZ_H
#define _MACIERZ_H

#include <stdio.h>

void inicjuj(FILE *plik);

void wymiary(int *x, int *y);

void wstaw(int w, int x);

void wstaw2(int w, int x, int y);

int wartosc(int x, int y);

int wartosc2(int x);

int czytaj(FILE *plik);

void wypisz();

void rysuj(FILE *plik);

void zapiszTXT(FILE *plik);

#endif
