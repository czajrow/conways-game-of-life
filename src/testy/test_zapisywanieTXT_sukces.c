#include "../macierz.h"


int main() {
  // given
  int czyBlad = 0;
  int porazka = 0;
  FILE *plik = fopen("daneTestowe", "r");
  if (plik == NULL)
    czyBlad = 1;
  inicjuj(plik);
  czytaj(plik);
  FILE *plikrys = fopen("TXTtestowe.txt", "wb");

  // when
  zapiszTXT(plikrys);

  // then
  fclose(plikrys);
  fclose(plik);
  plik = fopen("daneTestowe", "r");
  plikrys = fopen("TXTtestowe.txt", "r");
  int w[7 * 8];
  int k[7 * 8];
  int i;
  for (i = 0; i < 7 * 8; i++) {
    fscanf(plikrys, "%d", &w[i]);
    fscanf(plik, "%d", &k[i]);
    if (w[i] != k[i])
      porazka = 1;
  }

  puts("***********************************************************************"
       "************\n");

  if (czyBlad) {
    printf("%c[%dm ", 0x1B, 31);
    puts("\tNIEOCZEKIWANY BLAD!\n"
         "\tTEST `test_zapisywanieTXT_sukces` ZAKONCZONY "
         "PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  } else if (!porazka) {
    printf("%c[%dm ", 0x1B, 32);
    puts("\tFunkcja zapiszTXT() dziala poprawnie\n"
         "\tTEST `test_zapisywanieTXT_sukces` ZAKONCZONY "
         "SUKCESEM!");
    printf("%c[%dm ", 0x1B, 0);
  } else {
    printf("%c[%dm ", 0x1B, 31);
    puts("\tFunkcja zapiszTXT() nie dziala poprawnie\n"
         "\tTEST `test_zapisywanieTXT_sukces` ZAKONCZONY "
         "PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  }

  puts("\n*********************************************************************"
       "**************");
  fclose(plik);
  fclose(plikrys);
  return 0;
}
