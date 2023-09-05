CC=gcc
LIBS=-lm
LDIR=lib
IDIR=include
CFLAGS=-I$(IDIR) -L$(LDIR) -ggdb3 -Wall -Wextra -pedantic -static
OBJDIR=obj

_DEPS = dll.h ll.h stack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = acbase.o dll.o ll.o stack.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

acbase: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean: 
	rm -f $(OBJDIR)/*o
