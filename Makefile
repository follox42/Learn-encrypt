CC = gcc
CFLAGS = -Wall -Wextra -std=c99
BUILD_DIR = build

# Fundamentals
FUND_SRC = $(wildcard src/fundamentals/*.c)
FUND_BIN = $(patsubst src/fundamentals/%.c,$(BUILD_DIR)/fundamentals/%,$(FUND_SRC))

# Classical ciphers
CLASS_SRC = $(wildcard src/classical/*.c)
CLASS_BIN = $(patsubst src/classical/%.c,$(BUILD_DIR)/classical/%,$(CLASS_SRC))

all: fundamentals classical

fundamentals: $(FUND_BIN)

classical: $(CLASS_BIN)

$(BUILD_DIR)/fundamentals/%: src/fundamentals/%.c | $(BUILD_DIR)/fundamentals
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/classical/%: src/classical/%.c | $(BUILD_DIR)/classical
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/fundamentals:
	mkdir -p $@

$(BUILD_DIR)/classical:
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all fundamentals classical clean
