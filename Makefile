CPPFLAGS=--std=c++17
CC=g++
CFLAGS=-c -Wall
SOURCES=$(wildcard *.cpp)
EXECS=$(SOURCES:%.cpp=%)

all: $(EXECS)

clean:
	rm $(EXECS)