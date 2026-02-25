CC = gcc
CFLAGS = -Wall -Wextra -std=c99
BUILD_DIR = build

# Source directories
FUND_SRC = $(wildcard src/fundamentals/*.c)
CLASS_SRC = $(wildcard src/classical/*.c)
SYM_SRC = $(wildcard src/symmetric/*.c)
ASYM_SRC = $(wildcard src/asymmetric/*.c)
HASH_SRC = $(wildcard src/hashing/*.c)

# Build targets
FUND_BIN = $(patsubst src/fundamentals/%.c,$(BUILD_DIR)/fundamentals/%,$(FUND_SRC))
CLASS_BIN = $(patsubst src/classical/%.c,$(BUILD_DIR)/classical/%,$(CLASS_SRC))
SYM_BIN = $(patsubst src/symmetric/%.c,$(BUILD_DIR)/symmetric/%,$(SYM_SRC))
ASYM_BIN = $(patsubst src/asymmetric/%.c,$(BUILD_DIR)/asymmetric/%,$(ASYM_SRC))
HASH_BIN = $(patsubst src/hashing/%.c,$(BUILD_DIR)/hashing/%,$(HASH_SRC))

all: fundamentals classical symmetric asymmetric hashing

fundamentals: $(FUND_BIN)
classical: $(CLASS_BIN)
symmetric: $(SYM_BIN)
asymmetric: $(ASYM_BIN)
hashing: $(HASH_BIN)

$(BUILD_DIR)/fundamentals/%: src/fundamentals/%.c | $(BUILD_DIR)/fundamentals
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/classical/%: src/classical/%.c | $(BUILD_DIR)/classical
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/symmetric/%: src/symmetric/%.c | $(BUILD_DIR)/symmetric
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/asymmetric/%: src/asymmetric/%.c | $(BUILD_DIR)/asymmetric
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/hashing/%: src/hashing/%.c | $(BUILD_DIR)/hashing
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%:
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all fundamentals classical symmetric asymmetric hashing clean
