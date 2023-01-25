CXX = g++
EXEC = managementSystem
SOURCES = cpp/main.cpp cpp/Login.hpp cpp/Student.cpp cpp/Teacher.cpp cpp/Admin.cpp
OBJECTS = main.o 

.PHONY: all
all:
	$(CXX) $(SOURCES) -o $(EXEC)

.PHONY: clean
clean:
	rm -rf $(EXEC) *.gdb *.o *.out