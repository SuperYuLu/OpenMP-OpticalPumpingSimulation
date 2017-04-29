# Options
CC = g++
DEBUG = -g
CFLAGS = -c -O3

#Files
EXE = run
SRCS = main.cc calSpontEmission.cc
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = setValue.h transitionStrength.h main.h

#Rules
$(EXE): $(OBJS)
	$(CC)  $^ -o $@
calSpontEmission.o: calSpontEmission.cc setValue.h transitionStrength.h
	$(CC) $(CFLAGS) $(DEBUG) $<
main.o: main.cc main.h setValue.h transitionStrength.h
	$(CC) $(CFLAGS) $(DEBUG) $<
#Phony targets
clean:
	rm *.o *~

