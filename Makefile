all: orderBook

orderBook: main.o Order.o OrderBook.o MatchingEngine.o
	g++ -o orderBook main.o Order.o OrderBook.o MatchingEngine.o

MatchingEngine.o: src/MatchingEngine.cpp src/MatchingEngine.h
	g++ -c src/MatchingEngine.cpp

OrderBook.o: src/OrderBook.cpp src/OrderBook.h
	g++ -c src/OrderBook.cpp

Order.o: src/Order.cpp src/Order.h
	g++ -c src/Order.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o orderBook
