#include <stdlib.h>
#include <unistd.h>

#include "macierz.h"

typedef struct {
  int *tab;
  int x;
  int y;
} mac_t;

mac_t mac, mac2;

void inicjuj(FILE *plik) {
  int x, y;
  fscanf(plik, "%d %d\n", &x, &y);
  mac.tab = malloc(x * y * sizeof *mac.tab);
  mac2.tab = malloc(x * y * sizeof *mac2.tab);
  if (mac.tab == NULL || mac2.tab == NULL)
    exit(EXIT_FAILURE);
  mac.x = mac2.x = x;
  mac.y = mac2.y = y;
}

void wymiary(int *x, int *y) {
  *x = mac.x;
  *y = mac.y;
}

void wstaw(int w, int x) { mac.tab[x] = w; }

void wstaw2(int w, int x, int y) { mac2.tab[x + mac.x * y] = w; }

int wartosc(int x, int y) {
  if (x < 0 || x >= mac.x || y < 0 || y >= mac.y)
    return 0;
  return mac.tab[x + mac.x * y];
}

int wartosc2(int x) { return mac2.tab[x]; }

int czytaj(FILE *plik) {
  int i, j, w;
  for (i = 0; i < mac.y; i++)
    for (j = 0; j < mac.x; j++) {
      if (fscanf(plik, "%d", &w) == EOF)
        return 1;
      mac.tab[j + mac.x * i] = w;
    }
  return 0;
}

void wypisz(int clear, int interval) {
  if (clear) for (int i = 0; i < mac.y + 1; i++) printf("\033[1A");

  int i;
  for (i = 0; i < mac.x * mac.y; i++) {
    if (i % mac.x == 0) {
      printf("\n");
      printf("\033[K");
      if (interval > 0) usleep(interval * 1000);
    }
    if (mac.tab[i] == 0)
      printf("__");
    else
      printf("\u2588\u2588");
  }
  printf("\n");
}

void rysuj(FILE *plik) { // save img file
  int i;
  fprintf(plik, "P1\n%d %d\n", mac.x, mac.y);
  for (i = 0; i < mac.x * mac.y; ++i)
    fprintf(plik, "%d ", mac.tab[i]);
}

void zapiszTXT(FILE *plik) { // save txt file
  int i;
  fprintf(plik, "%d %d\n", mac.x, mac.y);
  for (i = 0; i < mac.x * mac.y; ++i) {
    if (i % mac.x == 0 && i != 0)
      fprintf(plik, "\n");
    fprintf(plik, "%d ", mac.tab[i]);
  }
}
