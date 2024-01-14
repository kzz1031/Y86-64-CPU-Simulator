CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp read.cpp memory.cpp Go.cpp fetch.cpp decode.cpp execute.cpp conditioncode.cpp _Memory.cpp writeback.cpp pc_update.cpp print.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=kzzcpu

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
