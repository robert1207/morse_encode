

CC = cc

CFLAGS = -Wall -g 

INCLUDES =

LFLAGS =

LIBS = -lm 

#define the C source files
SRCS = main.c morse.c

#define the C object files
OBJS = $(SRCS:.c=.o)

#define the executable fiel
MAIN = morsetest

.PHONY: depend clean

all:	$(MAIN)
		@echo the program of \" $(MAIN) \" has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

#
.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
