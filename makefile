CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o map.o player.o enemy.o shoot.o validation.o fileManager.o linkedList.o
EXEC = lasertank

#Add LOG to CFLAGS and recompile the program
ifdef LOG
CFLAGS += -D LOG
LOG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	
main.o : main.c main.h
	$(CC) -c main.c $(CFLAGS)
	
map.o : map.c map.h
	$(CC) -c map.c $(CFLAGS)
	
player.o : player.c player.h
	$(CC) -c player.c $(CFLAGS)
	
enemy.o : enemy.c enemy.h
	$(CC) -c enemy.c $(CFLAGS)

shoot.o : shoot.c shoot.h
	$(CC) -c shoot.c $(CFLAGS)

validation.o : validation.c validation.h
	$(CC) -c validation.c $(CFLAGS)

fileManager.o : fileManager.c fileManager.h
	$(CC) -c fileManager.c $(CFLAGS)

linkedList.o : linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)
	
clean: 
	rm -f $(EXEC) $(OBJ)