#include "../macierz.h"

int main() {
  // given
  int czyBlad = 0;
  int wynik;
  FILE *plik = fopen("bledneDaneTestowe", "r");
  if (plik == NULL)
    czyBlad = 1;
  inicjuj(plik);

  // when
  wynik = czytaj(plik);

  // then
  fclose(plik);
  puts("***********************************************************************"
       "************\n");

  if (czyBlad) {
    printf("%c[%dm ", 0x1B, 31);
    puts("\tNIEOCZEKIWANY BLAD!\n"
         "\tTEST `test_czytanieZPliku_bladSkladniPlikuTXT` ZAKONCZONY "
         "PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  } else if (wynik) {
    printf("%c[%dm ", 0x1B, 32);
    puts("\tBlad w skladni pliku `bledneDaneTestowe.txt`\n"
         "\tTEST `test_czytanieZPliku_bladSkladniPlikuTXT` ZAKONCZONY "
         "SUKCESEM!");
    printf("%c[%dm ", 0x1B, 0);
  } else {
    printf("%c[%dm ", 0x1B, 31);
    puts(
        "\tSkladnia pliku `bledneDaneTestowe.txt` jest poprawna\n"
        "\tTEST `test_czytanieZPliku_bladSkladniPlikuTXT` ZAKONCZONY PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  }

  puts("\n*********************************************************************"
       "**************");
  return 0;
}
