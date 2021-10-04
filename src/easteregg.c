#include "easteregg.h"
#include "generacja.h"
#include "macierz.h"
#include <stdlib.h>
#include <unistd.h>

void easteregg() {
  FILE *plik = fopen("dane/biblioteka/easteregg.txt", "r");
  if (plik != NULL) {
    inicjuj(plik);
    czytaj(plik);
    int n = 240;
    int k = n;
    while (n--) {

      for (int x = 0; x < 40; x++) {
        for (int i = 0; i < k - n + 1; i++) {
          printf("#");
        }
        for (int i = 0; i < n - 1; i++) {
          printf("*");
        }
        puts("");
      }
      generuj8();
      wypisz();
      usleep(50000);

      if (n == 1)
        exit(0);
    }
  }
}
