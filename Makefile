CXX = clang++
CXXFLAGS = -Wall -Wextra

TARGET_DIR = dist
TARGET = $(TARGET_DIR)/main

# Change it later, perhaps we'll have libs, etc
SRCS = src/main.cpp

all: $(TARGET) run

$(TARGET): $(SRCS)
	mkdir -p $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	$(TARGET)