all : headers/*.h src/*.cpp
	g++ -std=c++20 src/*.cpp -o solution

clean:
	rm -rf *.o
