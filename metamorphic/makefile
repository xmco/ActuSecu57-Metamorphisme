CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = metamorphic
RM = rm

G_FLAGS = -Wall -g -std=c++17

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(G_FLAGS)

%.o: %.cpp
	$(CC) $(G_FLAGS) -c $< -o $@

clean:
	$(RM) -f $(OBJ) $(TARGET)*

re: clean $(TARGET)