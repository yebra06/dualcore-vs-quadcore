# Programmer: Alfredo Yebra Jr.
# Date: March 20, 2016

#---- Target executable ----
TARGET 		= run
SRC 		= src
INCS 		= includes

# ---- Sources and Objects ----
SRCFILES	= $(wildcard $(SRC)/*.cpp)
OBJS 		= $(SRCFILES:.cpp=.o)

# ---- Compiler optiions ----
CXX			= g++
CFLAGS		= -g -Wall -I $(INCS)
RM			= rm -rf $(TARGET) $(SRC)/*.o

# make all
all: $(TARGET)

# Build executable from objects.
$(TARGET): 	$(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

# Recipe to generate object files from .cpp files.
%.o:		%.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

# Clean up objects and executables.
clean:
	$(RM)
