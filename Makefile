CardPool.o: CardPool.cpp CardPool.h
	g++ -pedantic-errors -std=c++11 $<

CardSet.o: CardSet.cpp CardSet.h
	g++ -pedantic-errors -std=c++11 $<

main.o:  main.cpp CardPool.h CardSet.h
	g++ -pedantic-errors -std=c++11 $<

main: CardPool.o CardSet.o main.o
	g++ $^ -o $@