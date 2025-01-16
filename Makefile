SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
LIB_DIR = lib
RAYLIB =$(LIB_DIR)/libraylib.a
CXX = g++
CXXFLAGS = -Wall -g -I$(INCLUDE_DIR)
RAYFLAGS = -L$(RAYLIB) -lraylib
TARGET = $(BIN_DIR)/flappy


SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX)  -o $@ $^ $(RAYFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

help:
	@echo "Usage: make [target]"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"