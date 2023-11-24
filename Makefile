CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
BUILD_DIR = build
EXECUTABLE = gerenciador
INPUT_FILE = database_imoveis

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar .cpp em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpar arquivos gerados depois da execução
.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)

# Executar e colocar o input do arquivo texto.
.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE) 
# < $(INPUT_FILE)
