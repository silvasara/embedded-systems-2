CC = gcc
LDFLAGS = -lwiringPi -lpthread 
CFLAGS = -c -Wall -I $(INC_DIR) -I $(BME280_LIB) -pedantic

BUILD_DIR = .
INC_DIR  = $(BUILD_DIR)/include
SRC_DIR  = $(BUILD_DIR)/src
OBJ_DIR  = $(BUILD_DIR)/obj
BIN_DIR  = $(BUILD_DIR)/bin
LIBS_DIR = $(BUILD_DIR)/lib

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
BIN = $(BIN_DIR)/bin

BME280_LIB = $(LIBS_DIR)/bme280


all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ_DIR)/*.o -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(OBJ_DIR)/bme280.o
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/bme280.o: $(BME280_LIB)/bme280.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)/*  $(BIN_DIR)/*

run:
	@$(BIN)
