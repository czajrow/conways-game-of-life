#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#include "easteregg.h"

#include "generacja.h"
#include "macierz.h"
//#include <unistd.h> // do usleep()

int main(int argc, char **argv) {
  // printf("Wybierz sasiedztwo:\n"
  //        "1. von Neumann'a\n"
  //        "2. Moore'a\n");
  // int sasiedztwo = 0;
  // scanf("%d", &sasiedztwo);
  // if (sasiedztwo == 291063)
  //   easteregg();
  // if (sasiedztwo != 1 && sasiedztwo != 2) {
  //   printf("Nie wybrales sasiedztwa\n");
  //   return 2;
  // }

  // printf("\nPodaj liczbe generacji do wykonania:\n");
  // int l_generacji = -1;
  // scanf("%d", &l_generacji);
  // if (l_generacji < 1 || l_generacji > 100) {
  //   printf("Liczba generacji musi sie zawierac w przedziale <1;100>");
  //   return 2;
  // }

  // printf("\nWybierz rodzaj danych:\n"
  //        "1. Wlasne (dane/dane.txt)\n"
  //        "2. Biblioteka\n");
  // int r_danych = 0;
  // scanf("%d", &r_danych);
  // if (r_danych != 1 && r_danych != 2) {
  //   printf("Nie wybrales rodzaju danych\n");
  // }

  int sasiedztwo = -1;
  int l_generacji = -1;
  char * path;

  int opt;

  while ((opt = getopt(argc, argv, "s:n:p:")) != -1) {
    switch (opt) {
    case 's':
      if (strcmp(optarg, "neumann") == 0) {
        sasiedztwo = 1;
      } else if (strcmp(optarg, "moore") == 0) {
        sasiedztwo = 2;
      }
      break;
    case 'n': printf("b; %s\n", optarg); break;
    case 'p': printf("c; %s\n", optarg); break;
    default:
      fprintf(stderr, "Usage: %s [-snp] [file...]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (sasiedztwo != 1 && sasiedztwo != 2) {
    printf("You must specify neighbourhood to be neumann or moore\n");
    return 6;
  }
  

  if (optind >= argc) {
    printf("Provide file name\n");
    return 4;
  } else {
    printf("File name: %s\n", argv[argc-1]);
  }
  

  printf("After\n");
  return 123;


  FILE *plik = NULL;
  plik = fopen("dane/dane.txt", "r");

  // if (r_danych == 1) {
  //   plik = fopen("dane/dane.txt", "r");
  //   if (plik == NULL) {
  //     printf("Ne udalo sie wczytac pliku\n");
  //     return 1;
  //   }
  // } else if (r_danych == 2) {
  //   printf("\nWybierz dane z biblioteki:\n"
  //          "1. Blinker\n"
  //          "2. Bochenek\n"
  //          "3. Fontanna\n"
  //          "4. Klocek\n"
  //          "5. Koniczynka\n"
  //          "6. Krokodyl\n"
  //          "7. Krysztal\n"
  //          "8. Niesmiertelna linia\n"
  //          "9. Lodz\n"
  //          "10. Staw\n"
  //          "11. Zaba\n");
  //   int dane = 0;
  //   scanf("%d", &dane);

  //   switch (dane) {
  //   case 1:
  //     plik = fopen("dane/biblioteka/blinker", "r");
  //     break;
  //   case 2:
  //     plik = fopen("dane/biblioteka/bochenek", "r");
  //     break;
  //   case 3:
  //     plik = fopen("dane/biblioteka/fontanna", "r");
  //     break;
  //   case 4:
  //     plik = fopen("dane/biblioteka/klocek", "r");
  //     break;
  //   case 5:
  //     plik = fopen("dane/biblioteka/koniczynka", "r");
  //     break;
  //   case 6:
  //     plik = fopen("dane/biblioteka/krokodyl", "r");
  //     break;
  //   case 7:
  //     plik = fopen("dane/biblioteka/krysztal", "r");
  //     break;
  //   case 8:
  //     plik = fopen("dane/biblioteka/linia_niesmiertelna", "r");
  //     break;
  //   case 9:
  //     plik = fopen("dane/biblioteka/lodz", "r");
  //     break;
  //   case 10:
  //     plik = fopen("dane/biblioteka/staw", "r");
  //     break;
  //   case 11:
  //     plik = fopen("dane/biblioteka/zaba", "r");
  //     break;
  //   default:
  //     printf("Nie wybrales danych z biblioteki\n");
  //     return 2;
  //   }
  // }

  if (plik == NULL) {
    printf("Nie udalo sie wczytac pliku\n");
    return 1;
  }

  inicjuj(plik);
  if (czytaj(plik)) {
    puts("Blad w skladni pliku TXT");
    return 3;
  }


  int nr_gen = 0;
  char krok = '1';

  while (nr_gen <= l_generacji) {
    // scanf("%c ", &krok);
    usleep(200000); //potrzeba unistd.h
    printf("Numer generacji: %d\n", nr_gen);
    wypisz();
    if (krok == 'q') {
      return 0;
    } else if (krok == 's') {
      char rys[64];
      sprintf(rys, "dane/wyniki/rys%d.pbm", nr_gen);
      FILE *plikrys = fopen(rys, "wb");
      rysuj(plikrys);
      fclose(plikrys);
      if (sasiedztwo == 1)
        generuj4();
      else
        generuj8();
      nr_gen++;
    } else if (krok > '1' && krok < '9') {
      int i;
      for (i = 0; i < krok - '0'; i++) {
        if (nr_gen <= l_generacji) {
          if (sasiedztwo == 1)
            generuj4();
          else
            generuj8();
          nr_gen++;
        }
      }
    } else if (krok == 't') {
      char rys[64];
      sprintf(rys, "dane/wyniki/gen%d.txt", nr_gen);
      FILE *pliktxt = fopen(rys, "wb");
      zapiszTXT(pliktxt);
      fclose(pliktxt);
      if (sasiedztwo == 1)
        generuj4();
      else
        generuj8();
      nr_gen++;
    } else {
      if (sasiedztwo == 1)
        generuj4();
      else
        generuj8();
      nr_gen++;
    }
  }
}
