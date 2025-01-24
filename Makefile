# Nome do executável
TARGET = Trabalho

# Compilador e flags
CXX = g++
CC = gcc
CXXFLAGS = -Wall -Iinclude
CFLAGS = -Wall -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Fontes C e C++
C_SOURCES = $(SRC_DIR)/sqlite3.c
CPP_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Objetos (C e C++)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_SOURCES)) \
          $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SOURCES))

# Regra principal
all: $(TARGET)

# Linkar todos os objetos (C e C++)
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar arquivos C++
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar arquivos C (SQLite)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretório de objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpar
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Executar
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run