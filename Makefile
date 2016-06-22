CC=gcc
CFLAGS=-I$(IDIR) -Wall
EXEC=slist-test
IDIR=./include
ODIR=obj

SLISTEXEC=slisttest
_SLISTSRC = slisttest.c
SLISTSRC = $(patsubst %,$(IDIR)/%,$(_SLISTSRC))
_SLISTDEPS = slist.c slist.h 
SLISTDEPS = $(patsubst %,$(IDIR)/%,$(_SLISTDEPS))
_SLISTOBJ = slist.o 
SLISTOBJ = $(patsubst %,$(ODIR)/%,$(_SLISTOBJ))


$(SLISTOBJ): $(SLISTDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

slist: $(SLISTOBJ) $(SLISTSRC)
	$(CC) -o $(SLISTEXEC) $^ $(CFLAGS)

DLISTEXEC=dlisttest
_DLISTSRC = dlisttest.c
DLISTSRC = $(patsubst %,$(IDIR)/%,$(_DLISTSRC))
_DLISTDEPS = dlist.c dlist.h 
DLISTDEPS = $(patsubst %,$(IDIR)/%,$(_DLISTDEPS))
_DLISTOBJ = dlist.o 
DLISTOBJ = $(patsubst %,$(ODIR)/%,$(_DLISTOBJ))


$(DLISTOBJ): $(DLISTDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dlist: $(DLISTOBJ) $(DLISTSRC)
	$(CC) -o $(DLISTEXEC) $^ $(CFLAGS)


HEAPEXEC=heaptest
_HEAPSRC = heaptest.c
HEAPSRC = $(patsubst %,$(IDIR)/%,$(_HEAPSRC))
_HEAPDEPS = heap.c heap.h 
HEAPDEPS = $(patsubst %,$(IDIR)/%,$(_HEAPDEPS))
_HEAPOBJ = heap.o 
HEAPOBJ = $(patsubst %,$(ODIR)/%,$(_HEAPOBJ))


$(HEAPOBJ): $(HEAPDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

heap: $(HEAPOBJ) $(HEAPSRC)
	$(CC) -o $(HEAPEXEC) $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SLISTEXEC) $(DLISTEXEC) $(HEAPEXEC) 
