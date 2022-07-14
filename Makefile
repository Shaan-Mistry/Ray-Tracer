EXECBIN  = raytracer

SOURCES  = $(wildcard *.cpp)
OBJECTS  = $(SOURCES:%.cpp=%.o)


CC       = g++ -std=c++17
CFLAGS   = -Wall -Wpedantic -Werror -Wextra
CLEAN    = rm -f
FORMAT   = clang-format -i

.PHONY: all clean format

all: $(EXECBIN)

$(EXECBIN): $(OBJECTS)
	$(CC) $^ -o $@ -lm

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	$(CLEAN) $(EXECBIN) $(OBJECTS)

format:
	$(FORMAT) $(SOURCES)
