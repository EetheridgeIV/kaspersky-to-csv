all: ConvertToCSV

ConvertToCSV: main.o
	g++ main.o -o ConvertToCSV

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o ConvertToCSV 1pass.csv
