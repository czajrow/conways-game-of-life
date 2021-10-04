#include "generacja.h"
#include "macierz.h"

void generuj8() {
  int x, y, x1, y1, x2, y2, n, i;
  wymiary(&x, &y);
  for (y1 = 0; y1 < y; y1++)     // po kolumnach
    for (x1 = 0; x1 < x; x1++) { // po wierszach
      n = 0;
      for (x2 = x1 - 1; x2 <= x1 + 1; x2++)   // sasiednie kolumny
        for (y2 = y1 - 1; y2 <= y1 + 1; y2++) // sasiednie wiersze
          if (wartosc((x2 + x) % x, (y2 + y) % y))
            n++;
      if (wartosc(x1, y1))
        n--;

      if (n == 3 || (n == 2 && wartosc(x1, y1)))
        wstaw2(1, x1, y1);
      else
        wstaw2(0, x1, y1);
    }
  for (i = 0; i < x * y; i++)
    wstaw(wartosc2(i), i);
}

void generuj4() {
  int x, y, x1, y1, x2, y2, n, i;
  wymiary(&x, &y);
  for (y1 = 0; y1 < y; y1++)     // po kolumnach
    for (x1 = 0; x1 < x; x1++) { // po wierszach
      n = 0;

      if (wartosc((x1 - 1 + x) % x, (y1 + y) % y))
        n++;
      if (wartosc((x1 + 1 + x) % x, (y1 + y) % y))
        n++;
      if (wartosc((x1 + x) % x, (y1 - 1 + y) % y))
        n++;
      if (wartosc((x1 + x) % x, (y1 + 1 + y) % y))
        n++;

      if (n == 3 || (n == 2 && wartosc(x1, y1)))
        wstaw2(1, x1, y1);
      else
        wstaw2(0, x1, y1);
    }
  for (i = 0; i < x * y; i++)
    wstaw(wartosc2(i), i);
}
