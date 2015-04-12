CC=g++
LDLIBS= 
SOURCES_DIR=src/
SOURCES=$(SOURCES_DIR)*.cc
INCLUDES_DIR=include/
CFLAGS=-g -Wall -std=c++11 -O2 -I$(INCLUDES_DIR) 

main:	clean
	$(CC) $(CFLAGS) $(LD_LIBS) $@.cc $(SOURCES) -o $@

clean:
	rm -fvr *~ $(INCLUDE_DIR)*~ $(SOURCES_DIR)*~ *.dSYM main 

%:
	$(CC) $(CFLAGS) $(LDLIBS) $@.cc -o $@
