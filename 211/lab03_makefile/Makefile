foobar: main.o foo.o bar.o
	g++ -Wall -pedantic -std=c++11 -g -o foobar main.o foo.o bar.o

main.o: main.cpp foo.h bar.h
	g++ -Wall -pedantic -std=c++11 -g -c main.cpp

foo.o: foo.cpp foo.h
	g++ -Wall -pedantic -std=c++11 -g -c foo.cpp

bar.o: bar.cpp bar.h
	g++ -Wall -pedantic -std=c++11 -g -c bar.cpp

clean:
	rm -f foobar main.o foo.o bar.o
