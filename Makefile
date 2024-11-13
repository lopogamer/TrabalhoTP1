# Nome do executável
TARGET = Trabalho

# Compilador e flags de compilação
CXX = g++
CXXFLAGS = -Wall -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Lista de arquivos-fonte e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Regra principal: compilar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar cada arquivo objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criação do diretório de objetos, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza de arquivos objeto e executável
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Regra para compilar e executar o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
