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
EXECS=dico

SRCS_0=dico.c
OBJS_0=${SRCS_0:.c=.o}

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXECS)

dico: $(OBJS_0)
	$(CC) $(CFLAGS) -o dico $(OBJS_0) $(LDFLAGS) $(LIBRARIES)

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------
clean_dico:
	rm -f dico $(OBJS_0)

clean: clean_dico
