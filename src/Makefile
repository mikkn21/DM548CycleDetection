#SAN_FLAGS = -fsanitize=address  -fsanitize=undefined   -fsanitize=leak
CFLAGS = -Wall -Wextra -g -O2 $(SAN_FLAGS)
LDLIBS = -lm
LDFLAGS = cycleDetection.c Graph.c LinkedList.c $(SAN_FLAGS)


detectCycles:
	$(CC) $(SAN_FLAGS) $(LDFLAGS) -o  $@  main.c  $(LDLIBS)

.PHONY: clean
clean:
	rm -f *.o detectCycles a.out prog
