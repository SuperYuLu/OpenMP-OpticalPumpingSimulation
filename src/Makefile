# Options
# For gnu compiler
CC = g++
DEBUG = -g
CFLAGS = -c -fopenmp
# For intel compiler
#CC = icpc
#CFLAGS = -c -openmp

#Files
EXE = run
SRCS = main_OMP.cc 
OBJS = $(patsubst %.cc, %.o, $(SRCS))
HEADS = Li7DLine.h main.h

#Rules
$(EXE): $(OBJS)
	$(CC) $^ -o $@

main_OMP.o: main_OMP.cc main.h Li7DLine.h setValues.h
	$(CC) $(CFLAGS) $<

#Phony targets
plot:
	python3 plotPopulation.py
clean:
	rm *.o *~
