CC := g++
CFLAGS ?= -Wall -Werror -g -std=c++11
LDLIBS ?= -lm

EXEC = echecs

INCLUDE_PATH ?= ./includes
SRC_PATH = ./src
OBJ_PATH = ./obj
BIN_PATH = ./bin

SOURCES := $(filter-out $(SRC_PATH)/main.cc, $(wildcard $(SRC_PATH)/*.cc $(SRC_PATH)/*/*.cc $(SRC_PATH)/*/*/*.cc))
INCLUDES := $(wildcard $(INCLUDE_PATH)/*.hpp $(INCLUDE_PATH)/*/*.hpp $(INCLUDE_PATH)/*/*/*.hpp)
OBJECTS  := $(SOURCES:$(SRC_PATH)/%.cc=$(OBJ_PATH)/%.o)

.PHONY: cli
cli:
	$(MAKE) $(BIN_PATH)/$(EXEC)

docs:
	mkdir -p ./docs
	doxygen Doxyfile

$(BIN_PATH)/$(EXEC): $(OBJ_PATH)/main.o $(OBJECTS)
	mkdir -p $(BIN_PATH)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.cc 
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH) 

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.cc
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)


.PHONY: clean
clean:
	rm -fr $(OBJ_PATH)
	rm -fr $(BIN_PATH)
	rm test.log
