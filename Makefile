CC=gcc
CFLAGS=-Iinclude -Wall
SRC_DIR=src
OBJ_DIR=build
TARGET=pos_102

# Find all source files
SRCS=$(wildcard $(SRC_DIR)/*.c)
# Create object file names from source file names
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # Create build directory if it doesn't exist.
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts.
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)