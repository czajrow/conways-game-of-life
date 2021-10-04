#include "../macierz.h"

int main() {

  // given
  int czyBlad = 0;
  FILE *plik = fopen("daneTestowe", "r");
  if (plik == NULL)
    czyBlad = 1;
  int x = 0;
  int y = 0;
  int oczekiwanyX = 7;
  int oczekiwanyY = 8;
  inicjuj(plik);

  // when
  wymiary(&x, &y);

  // then
  fclose(plik);
  puts("***********************************************************************"
       "************\n");

  if (czyBlad) {
    printf("%c[%dm ", 0x1B, 31);
    puts("\tNIEOCZEKIWANY BLAD!\n"
         "\tTEST `wymiary()_wypisujeNaStdoutWymiaryx7y8` ZAKONCZONY "
         "PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  } else if (x == oczekiwanyX && y != oczekiwanyY) {
    printf("%c[%dm ", 0x1B, 32);
    printf("\t(x,y) = (%d,%d)\n", x, y);
    puts("\tTEST `wymiary()_wypisujeNaStdoutWymiaryx7y8` ZAKONCZONY SUKCESEM!");
    printf("%c[%dm ", 0x1B, 0);
  } else {
    printf("%c[%dm ", 0x1B, 31);
    printf("\t(x,y) = (%d,%d)\n", x, y);
    puts("\tTEST `wymiary()_wypisujeNaStdoutWymiaryx7y8` ZAKONCZONY PORAZKA!");
    printf("%c[%dm ", 0x1B, 0);
  }

  puts("\n*********************************************************************"
       "**************");
  return 0;
}
