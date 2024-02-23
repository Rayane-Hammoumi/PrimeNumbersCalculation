CC = gcc
CFLAGS = -Wall
VERSIONS = iterative recursive iterative_avec_table_recherche
SOURCES = main.c iteratif.c recursif.c iteratif_avec_table.c
EXECUTABLES = $(addprefix version_, $(VERSIONS))

all: clean $(EXECUTABLES)

version_%: $(SOURCES)
	$(CC) $(CFLAGS) -D$* $^ -o $@

clean:
	rm -Rf *~ $(EXECUTABLES)