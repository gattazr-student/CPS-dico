##################################################
#        Makefile automatically generated        #
# Brought to you by Jules HABLOT and Rémi GATTAZ #
##################################################

#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC=gcc
CFLAGS=-g -Wall -pedantic -I../include
LDFLAGS=-L../lib/libmacos64
LIBRARIES=-ltokenize

SRCS=main.c
OBJS=${SRCS:.c=.o}
EXEC=main

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBRARIES)

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------
clean:
	rm -f $(OBJS)

mr_proper: clean
	rm -f $(EXEC)

.PHONY: mr_proper clean