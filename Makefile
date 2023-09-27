CC = gcc

CHECK = -std=c11 -Wall -Werror -Wextra

TARGET = ../build/graph

all : graph.o polish_logic.o print_module.o stack_functions.o string_management.o

	$(CC) graph.o polish_logic.o print_module.o stack_functions.o string_management.o -o $(TARGET)

	mv *.o ../build

graph.o : graph.c 

	$(CC) $(CHECK) -c graph.c

polish_logic.o : polish_logic.c

	$(CC) $(CHECK) -c polish_logic.c

print_module.o : print_module.c

	$(CC) $(CHECK) -c print_module.c

stack_functions.o : stack_functions.c

	$(CC) $(CHECK) -c stack_functions.c

string_management.o : string_management.c

	$(CC) $(CHECK) -c string_management.c

clean : 

	rm ../build/graph ../build/*.o

rebuild:

	make clean

	make all


