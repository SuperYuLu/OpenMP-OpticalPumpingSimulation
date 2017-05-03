# Options
CC = g++
DEBUG = -g
CFLAGS = -c

#Files
EXE = run
SRCS = main.cc 
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = Li7DLine.h main.h

#Rules
$(EXE): $(OBJS)
	$(CC) $^ -o $@

main.o: main.cc main.h Li7DLine.h setValues.h
	$(CC) $(CFLAGS) $<

#Phony targets
plot:
	python3 plotPopulation.py
clean:
	rm *.o *~
