# Options
CC = g++
DEBUG = -g
CFLAGS = -c

#Files
EXE = run
SRCS = main.cc calSpontaneousEmission.cc
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = setValue.h transitionStrength.h main.h

#Rules
$(EXE): $(OBJS)
	$(CC) $^ -o $@
calSpontaneousEmission.o: calSpontaneousEmission.cc setValue.h transitionStrength.h
	$(CC) $(CFLAGS) $<
main.o: main.cc main.h setValue.h transitionStrength.h
	$(CC) $(CFLAGS) $<
#Phony targets
clean:
	rm *.o *~

