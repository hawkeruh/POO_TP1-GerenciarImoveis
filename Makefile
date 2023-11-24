CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
BUILD_DIR = build
EXECUTABLE = corretora

# Caminho dos arquivos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(SRC_DIR)

# Cria uma pasta build se não existir
$(BUILD_DIR):
	mkdir -p $@

# Limpa
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
