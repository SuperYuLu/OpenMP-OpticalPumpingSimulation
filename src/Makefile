# Options
CC = g++
DEBUG = -g
CFLAGS = -c

#Files
EXE = run
SRCS = main.cc
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = Li7DLine.h

#Rules
$(EXE): $(OBJS)
	$(CC) $^ -o $@
main.o: main.cc Li7DLine.h
	$(CC) $(CFLAGS) $<

#Phony targets
clean:
	rm *.o *~
