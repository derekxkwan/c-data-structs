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

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SLISTEXEC)
