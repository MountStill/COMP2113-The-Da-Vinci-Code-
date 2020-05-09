FLAGS = -pedantic-errors -std=c++11

CardPool.o: CardPool.cpp CardPool.h
	g++ $(FLAGS) -c $<

CardSet.o: CardSet.cpp CardSet.h
	g++ $(FLAGS) -c $<

main.o: main.cpp CardPool.h CardSet.h
	g++ $(FLAGS) -c $<

main: CardPool.o CardSet.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f CardPool.o CardSet.o main.o main

run:
	./main

.PHONY: clean
