program:derle calistir	
derle:
	g++ -I "./include" -c ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -I "./include" -c ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -I "./include" -c ./src/Source.cpp -o ./lib/Source.o
	g++ ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/Source.o -o ./bin/veriyapilari
calistir:
	./bin/veriyapilari
	