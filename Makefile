TEST_TARGET := roman_calculator_test

SRC_DIR := src
TEST_DIR := test
TARGET_DIR := target

CC := gcc
CFLAGS := -g -Wall -std=c99

all: roman_calculator

roman_calculator: $(TEST_DIR)/$(TEST_TARGET).c | $(TARGET_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/*.c $(TEST_DIR)/$(TEST_TARGET).c -o $(TARGET_DIR)/$(TEST_TARGET) `pkg-config --libs check`
	./$(TARGET_DIR)/$(TEST_TARGET)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

.PHONY: clean
clean:
	rm -rf $(TARGET_DIR)