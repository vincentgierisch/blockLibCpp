# declaring some variables
COMPILER := g++
TARGET := bin/openGLTest
LIB := -lglfw -lrt -lm -ldl -lm -pthread -lrt -lffi -lGL -lGLEW
BINDIR := bin
SRCDIR := src
BUILDDIR := build
CFLAGS := -std=c++17 -O3 -g

# execute shell command 'find': src/test1.cpp src/test2.cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.cpp)

# LIBSOURCES := $(shell
# replace .cpp with .o
OBJECTFILES := $(SOURCES:.cpp=.o)
# replace src/* with build/*
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(OBJECTFILES))

# target: dependencie
# $^ lists all dependencies in that manner: dependencie1 dependencie2
# the target (executable) depends on all objects files
# @ will disable the output
$(TARGET): $(OBJECTS)
	@echo "Linking $(OBJECTS)"
	@mkdir -p $(BINDIR)
	@$(COMPILER) $^ -o $(TARGET) $(LIB)

# compile object files
# $@ = target (in this case build/%.o)
# $< = dependencie (in this case src/%.d)
# so everything that matches target (% acts as some kind of wildcard here) goes in here
# the percent (%) in the dependencie is replaced with what ever the percent in target matches
# -o prevents compiler from linking the files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR) $(BUILDDIR)/ogl $(BUILDDIR)/utils
	@$(COMPILER) $(CFLAGS) -c -o $@ $^
	@echo "[Compiled] $@"

clean:
	@echo "Let me clean that for you..."
	@rm -rf $(BINDIR) $(BUILDDIR)
	
all: $(TARGET)

.PHONY: all clean test

test:
	echo $(wildcard src/*.cpp)
