start: testy_bin/test_czytanieZPliku_bladSkladniPlikuTXT testy_bin/test_pobieranieWymiarow_x7y8 testy_bin/test_rysowaniePBM_czyPoprawnieRysuje testy_bin/test_czytanieWartosci_sukces testy_bin/test_zapisywanieTXT_sukces
	testy_bin/test_czytanieZPliku_bladSkladniPlikuTXT
	testy_bin/test_pobieranieWymiarow_x7y8
	testy_bin/test_rysowaniePBM_czyPoprawnieRysuje
	testy_bin/test_czytanieWartosci_sukces
	testy_bin/test_zapisywanieTXT_sukces


testy_bin/test_pobieranieWymiarow_x7y8: test_pobieranieWymiarow_x7y8.o macierz.o
	$(CC) -Wall --pedantic -o testy_bin/test_pobieranieWymiarow_x7y8 test_pobieranieWymiarow_x7y8.o macierz.o

testy_bin/test_czytanieZPliku_bladSkladniPlikuTXT: test_czytanieZPliku_bladSkladniPlikuTXT.o macierz.o
	$(CC) -Wall --pedantic -o testy_bin/test_czytanieZPliku_bladSkladniPlikuTXT test_czytanieZPliku_bladSkladniPlikuTXT.o macierz.o

testy_bin/test_rysowaniePBM_czyPoprawnieRysuje: test_rysowaniePBM_czyPoprawnieRysuje.o macierz.o
	$(CC) -Wall --pedantic -o testy_bin/test_rysowaniePBM_czyPoprawnieRysuje test_rysowaniePBM_czyPoprawnieRysuje.o macierz.o

testy_bin/test_czytanieWartosci_sukces: test_czytanieWartosci_sukces.o macierz.o
	$(CC) -Wall --pedantic -o testy_bin/test_czytanieWartosci_sukces test_czytanieWartosci_sukces.o macierz.o

testy_bin/test_zapisywanieTXT_sukces: test_zapisywanieTXT_sukces.o macierz.o
	$(CC) -Wall --pedantic -o testy_bin/test_zapisywanieTXT_sukces test_zapisywanieTXT_sukces.o macierz.o


macierz.o: ../macierz.c
	$(CC) -c ../macierz.c -o macierz.o

clean:
	-rm testy_bin/*
	-rm *.o
	-rm *.pbm
	-rm *.txt
