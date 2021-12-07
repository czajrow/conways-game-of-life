#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#include "generacja.h"
#include "macierz.h"
//#include <unistd.h> // do usleep()

void display_helper();

int main(int argc, char **argv) {
  int sasiedztwo = -1;
  int l_generacji = -1;
  char * path;
  int display_results = 0; // bool - display results on screen, or not
  int save_results = 0; // bool - save results as images or not
  int save_results_txt = 0; // bool - save results as txt or not
  int interval = 50; // interval of displaying on the screen
  int speedMode = 0; // interval mode. 0 - per image, 1 - per line


  char opt;

  while ((opt = getopt(argc, argv, "s:n:v:m:dith")) != -1) {
    switch (opt) {
      case 's': // neighbourhood (4 or 8 neighbours)
        if (strcmp(optarg, "neumann") == 0) {
          sasiedztwo = 1;
        } else if (strcmp(optarg, "moore") == 0) {
          sasiedztwo = 2;
        }
        break;
      case 'n': // number of generations to run
        l_generacji = atoi(optarg);
        break;
      case 'v': // interval of displaying
        interval = atoi(optarg);
        break;
      case 'm': // interval mode
        if (strcmp(optarg, "image") == 0) {
          speedMode = 0;
        } else if (strcmp(optarg, "line") == 0) {
          speedMode = 1;
        } else {
          speedMode = -1;
        }
        break;
      case 'd': display_results = 1; break; // display results on screen, or not
      case 'i': save_results = 1; break; // save results as images or not
      case 't': save_results_txt = 1; break; // save results as txt or not
      case 'h':
        display_helper();
        return 0;
      default:
        fprintf(stderr, "Usage: %s [s:n:v:m:dith] [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  if (sasiedztwo != 1 && sasiedztwo != 2) {
    printf("You must specify neighbourhood to be \"neumann\" or \"moore\"\n");
    return 6;
  }

  if (speedMode != 0 && speedMode != 1) {
    printf("Speed mode must be \"image\" or \"line\"\n");
    return 6;
  }

  if (l_generacji < 1 || l_generacji > 10000) {
    printf("Number of generations must be between 1 and 10000\n");
    return 6;
  }

  if (interval < 1 || interval > 5000) {
    printf("Speed must be between 1 and 5000\n");
    return 6;
  }


  if (optind >= argc) {
    printf("Provide file name\n");
    return 4;
  } else {
    path = argv[argc-1];
  }

  FILE *plik = NULL;
  plik = fopen(path, "r");

  if (plik == NULL) {
    printf("Couldn't read file: %s\n", path);
    return 1;
  }

  inicjuj(plik);
  if (czytaj(plik)) {
    printf("Error in file syntax: %s\n", path);
    return 3;
  }
  fclose(plik);

  for (int i = 0; i < l_generacji; i++) {
    if (sasiedztwo == 1) generuj4(); else generuj8();
    if (display_results) {
      if (i > 0 && speedMode == 0) usleep(interval * 1000);
      wypisz(i > 0 ? 1 : 0, interval * speedMode);
    }
    if (save_results) {
      char rys[64];
      sprintf(rys, "dane/wyniki/rys%d.pbm", i + 1);
      FILE *plikrys = fopen(rys, "wb");
      rysuj(plikrys);
      fclose(plikrys);
    }
    if (save_results_txt) {
      char rys[64];
      sprintf(rys, "dane/wyniki/gen%d.txt", i + 1);
      FILE *pliktxt = fopen(rys, "wb");
      zapiszTXT(pliktxt);
      fclose(pliktxt);
    }
  }

  return 0;
}

void display_helper() {
  int c;
  FILE *file;
  file = fopen("dane/helper.txt", "r");
  if (file) {
      while ((c = getc(file)) != EOF)
          putchar(c);
      fclose(file);
  } else {
    printf("Error printing helper\n");
  }
}
