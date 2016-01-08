LBASE  = -lpthread

CXX = g++
CXXFLAGS = -std=c++11 -g -O3

test: test.o twait.o
	${CXX} -otest test.o twait.o ${LBASE}

clean:
	rm -f test
	rm -f *.o

