# =========================================================================
# Source files, Object files, etc...
# =========================================================================

DIR_INC  := $(wildcard include)
DIR_SRC  := $(wildcard src)
DIR_OBJ  := $(wildcard obj)
DIR_BIN  := ../bin

EXT      := cc
INCLUDE  := -I$(DIR_INC)
SRC      := $(wildcard $(DIR_SRC)/*.$(EXT))
OBJ      := $(patsubst $(DIR_SRC)/%.$(EXT), $(DIR_OBJ)/%.o, $(SRC))
#OBJ      := $(patsubst %.$(EXT), $(DIR_OBJ)/%.o, $(notdir $(SRC)))
TARGET   := $(DIR_BIN)/main

# =========================================================================
# Make variables (CC, etc...)
# =========================================================================

CC         := clang 
CFLAGS     := -Wall
CXX        := clang++
CXXFLAGS   := -Wall -std=c++11

# =========================================================================
# Rules shared between targets and prerequisites
# =========================================================================

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.$(EXT)
	$(CC) -c $^ -o $@ $(CXXFLAGS) $(INCLUDE)

PHONY += clean
clean: 
	rm -f $(TARGET) $(OBJ)

.PHONY: PHONY
