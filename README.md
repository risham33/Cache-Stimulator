Cache-Stimulator
================
#this is a comment
COMPILER = gcc
CCFLAGS = -ansi -pedantic -Wall
all: sim

debug:
	make DEBUG=TRUE

sim: cache-sim.o
	$(COMPILER) $(CCFLAGS) -o sim cache-sim.o
cache-sim.o: sim.c
	$(COMPILER) $(CCFLAGS) -c sim.c

ifeq ($(DEBUG), TRUE)
 CCFLAGS += -g
endif

clean:
	rm -f sim
	rm -f *.o
