#include "../macierz.h"

int main() {
  // given
  int czyBlad = 0;
  int wynik = 0;
  FILE *plik = fopen("DaneTestowe", "r");
  if (plik == NULL)
    czyBlad = 1;
  inicjuj(plik);
  czytaj(plik);
  int a1 = -1, a2 = -1, a3 = -1, a4 = -1, a5 = -1;
  int e1 = 0, e2 = 1, e3 = 1, e4 = 0, e5 = 0;

  // when
  a1 = wartosc(2, 1);
  a2 = wartosc(2, 3);
  a3 = wartosc(1, 5);
  a4 = wartosc(3, 4);
  a5 = wartosc(6, 3);

  // then
  fclose(plik);

  if (a1 == e1 && a2 == e2 && a3 == e3 && a4 == e4 && a5 == e5)
    wynik = 1;

  puts("***********************************************************************"
       "************\n");

  if (czyBlad) {
    printf("%c[%dm ", 0x1B, 31);
    puts("\tNIEOCZEKIWANY BLAD!\n"
         "\tTEST `test_czytanieWartosci_sukces` ZAKONCZONY "
         "PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  } else if (wynik) {
    printf("%c[%dm ", 0x1B, 32);
    puts("\tFunkcja wartosc() dziala poprawnie\n"
         "\tTEST `test_czytanieWartosci_sukces` ZAKONCZONY "
         "SUKCESEM!");
    printf("%c[%dm ", 0x1B, 0);
  } else {
    printf("%c[%dm ", 0x1B, 31);
    puts("\tFunkcja wartosc() nie dziala poprawnie\n"
         "\tTEST `test_czytanieWartosci_sukces` ZAKONCZONY PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  }

  puts("\n*********************************************************************"
       "**************");
  return 0;
}
