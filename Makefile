# Nome do executável
TARGET = Trabalho

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -I$(INCLUDE_DIR) -Ilib  # Adiciona busca por headers na pasta lib

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Arquivos-fonte e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Regra principal
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS)

# Compilação de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criação do diretório obj
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza (Linux)
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Limpeza (Windows)
clean-win:
	if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	if exist $(TARGET).exe del /q $(TARGET).exe

# Executar
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean clean-win run