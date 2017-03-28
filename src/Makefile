# Options
CC = g++
DEBUG = -g
CFLAGS = -c

#Files
EXE = run
SRCS = main.cc
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = atoms.h setValue.h transitionStrength.h

#Rules
$(EXE): $(OBJS)
	$(CC) $^ -o $@
main.o: main.cc atoms.h setValue.h transitionStrength.h
	$(CC) $(CFLAGS) $<

#Phony targets
clean:
	rm *.o *~

