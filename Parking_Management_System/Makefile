CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11

SRC := main.cpp parking.cpp
OBJ := $(SRC:.cpp=.o)
EXE := parking_system.exe

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $(EXE)

%.o: %.cpp parking.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(OBJ) $(EXE)