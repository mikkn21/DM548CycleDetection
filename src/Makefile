SAN_FLAGS = -fsanitize=address  -fsanitize=undefined  # -fsanitize=leak
CFLAGS = -Wall -Wextra -g -O2 $(SAN_FLAGS)
LDLIBS = -lm
CPPFLAGS = cycleDetection.c Graph.c LinkedList.c
# LDFLAGS = cycleDetection.h Graph.h LinkedList.h  $(SAN_FLAGS)



FILE = main.o


detectCycles: $(FILE)
	$(CC) $(SAN_FLAGS) $(LDFLAGS) -o  $@  $^  $(LDLIBS)

.PHONY: clean
clean:
	rm -f *.o detectCycles a.out
