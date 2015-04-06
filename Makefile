CC=clang++
CFLAGS=-g -Wall -std=c++11 -O2
LDLIBS= 
SOURCES=utilities.cc file_parser.cc readers.cc

main:	clean
	$(CC) $(CFLAGS) $(LD_LIBS) $@.cc $(SOURCES) -o $@

clean:
	rm -f *~ main 

%:
	$(CC) $(CFLAGS) $(LDLIBS) $@.cc -o $@
