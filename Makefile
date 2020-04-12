# leads comments in a line 
# Build all: default target
all : demo

newg++ = g++ -std=c++11

# Separate compilation to build object files
main.o : main.cpp sort.h 
	$(newg++) -c -ggdb main.cpp -pthread

sort.o : sort.cpp sort.h 
	$(newg++) -c -ggdb sort.cpp

# linking
demo : main.o sort.o
	$(newg++) main.o sort.o -o demo -pthread
	@echo 'executable "demo" has been created'

# Testing
check : all
	./demo

# Clean up all build targets so that one may get a clean build
clean :
	rm -f  vgcore.* core.* *.o demo

# Debuging
#debug : all
#	gdb demo

# Check for memory leaks
#valgrind : all
#	valgrind --leak-check=yes ./demo
