build: bin/life

run: bin/life
	bin/life

bin/life: src/main.o src/macierz.o src/generacja.o
	$(CC) -Wall --pedantic -o bin/life  src/main.o src/macierz.o src/generacja.o

clean:
	-rm src/*.o
	-rm bin/life
	-rm dane/wyniki/*.pbm
	-rm dane/wyniki/*.txt
