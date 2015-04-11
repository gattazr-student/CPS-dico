##################################################
#        Makefile automatically generated        #
# Brought to you by Jules HABLOT and Rémi GATTAZ #
##################################################

#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC=gcc
CFLAGS=-g -Wall -pedantic -I../include
LDFLAGS=
LIBRARIES=-ltokenize

SRCS=main.c maillon.c mot.c dictionnaire.c
OBJS=${SRCS:.c=.o}
EXEC=dico

#-------------------------------------------------
#            Adapt Makefile to target
#-------------------------------------------------
# Adaptation a Darwin / MacOS X
ifeq ($(shell uname -sm), Darwin x86_64)
LDFLAGS+= -L../lib/libmacos64
endif

# Adaptation a Linux64
ifeq ($(shell uname -sm), Linux x86_64)
LDFLAGS+=-L../lib/liblinux64
endif

ifeq ($(shell uname -sm), Darwin x86)
LDFLAGS+=-L../lib/liblinux32
endif


#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBRARIES)

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------
main.o: main.c ../include/types.h
maillon.o: maillon.c ../include/maillon.h ../include/types.h
mot.o: mot.c ../include/mot.h maillon.c ../include/types.h
dictionnaire.o: dictionnaire.c ../include/dictionnaire.h ../include/mot.h ../include/types.h

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------
clean:
	rm -f $(OBJS)

mrproper: clean
	rm -f $(EXEC)

.PHONY: mrproper clean
