# location of header files
IDIR = ../include

# compiler to use
CC = gcc

# compiler flags
CP = -Wall
CFLAGS = -I$(IDIR) -lXi -lXmu -lglut -lGLEW -lGLU -lm -lGL

# header dependencies
_DEPS = initShader.h track.h geometricShapes.h matrixOperations.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# object files
ODIR = obj
_OBJ = initShader.o track.o geometricShapes.o matrixOperations.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: cylinder sphere torus spring

cylinder: cylinder.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CP)

sphere: sphere.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

torus: torus.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

spring: spring.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

$(ODIR)/%.o: %.c $(IDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
