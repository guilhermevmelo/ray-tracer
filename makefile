PROJECT=raytracer

CPP_SOURCES=$(wildcard *.cpp)
CPP_HEADERS=$(wildcard *.h)
OBJECTS=$(CPP_SOURCES: .cpp=.o)

CC=g++
CC_FLAGS=-c

all: $(PROJECT) clean
 
$(PROJECT): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $^

clean:
	@rm -rf *.o