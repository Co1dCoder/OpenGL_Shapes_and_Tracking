LIBS = -lXi -lXmu -lglut -lGLEW -lGLU -lm -lGL

torus: spring.c initShader.o track.o geometricShapes.o matrixOperations.o
	gcc -g -o spring spring.c initShader.o track.o geometricShapes.o matrixOperations.o $(LIBS)

track.o: track.c track.h
	gcc -c track.c -lm

geometricShapes.o: geometricShapes.c geometricShapes.h
	gcc -c geometricShapes.c -lm

initShader.o: initShader.c initShader.h
	gcc -c initShader.c

matrixOperations.o: matrixOperations.c matrixOperations.h
	gcc -c matrixOperations.c  -lm
