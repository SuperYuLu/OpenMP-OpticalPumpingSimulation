# Options

# For gnu compiler
#CC = g++
#DEBUG = -g
#CFLAGS = -c -fopenmp

# For intel compiler
CC = icpc
CFLAGS = -xHost -qopenmp  -c 
OFLAGS = -xHost -qopenmp  -o

#Files
EXE = run
SRCS = main_OMP.cc 
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = Li7DLine.h main.h

#Rules
$(EXE): $(OBJS)
	$(CC) $^ $(OFLAGS) $@

main_OMP.o: main_OMP.cc main.h Li7DLine.h setValues.h
	$(CC) $(CFLAGS) $<

#Phony targets
plot:
	python plotPopulation.py
clean:
	rm *.o *~
