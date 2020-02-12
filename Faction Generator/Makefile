CXXFLAGS := -std=c++11

TARGET := Faction\ Generator

BUILD := ../Build
OBJ_DIR := $(BUILD)/Objects
PRODUCTS_DIR := $(BUILD)/Products

SRC := $(wildcard *.cpp)

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

buildroot: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: buildroot build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: APP_DIR = $(PRODUCTS_DIR)/Debug
debug: buildroot

release: APP_DIR = $(PRODUCTS_DIR)/Release
release: buildroot

clean:
	-@rm -rvf $(OBJ_DIR)
	-@rm -rvf $(PRODUCTS_DIR)