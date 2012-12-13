
start:
	@echo "start to compile the programm"
	$(CC) -Wall -Wextra -g -o pf programmfinder.c

clean:
	rm ./pf