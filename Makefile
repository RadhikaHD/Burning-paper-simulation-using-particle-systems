CC      = g++
C	= cpp
H	= h

CFLAGS = -g

ifeq ("$(shell uname)", "Darwin")
  LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lm
else
  ifeq ("$(shell uname)", "Linux")
    LDFLAGS     = -lglut -lGL -lGLU -lm
  endif
endif

HFILES = Vector.${H} Utility.${H} Camera.${H} Matrix.${H} Paper.${H} Simulator.${H} Particle.${H}
OFILES = Vector.o Utility.o Camera.o Matrix.o Paper.o Simulator.o Particle.o
PROJECT = main

${PROJECT}:	${PROJECT}.o ${OFILES}
	${CC} ${CFLAGS} -o ${PROJECT} ${PROJECT}.o ${OFILES} ${LDFLAGS}

${PROJECT}.o: ${PROJECT}.${C} ${HFILES}
	${CC} ${CFLAGS} -c ${PROJECT}.${C}

Vector.o: Vector.${C} Vector.${H} Utility.${H} 
	${CC} ${CFLAGS} -c Vector.${C}

Utility.o: Utility.${C} Utility.${H}
	${CC} ${CFLAGS} -c Utility.${C}

Camera.o: Camera.${C} Camera.${H} Matrix.${H}
	${CC} ${CFLAGS} -c Camera.${C}

Paper.o: Paper.${C} Matrix.${H} Vector.${H} Paper.${H} Particle.${H}
	${CC} ${CFLAGS} -c Paper.${C}

Particle.o: Particle.${C} Particle.${H} Vector.${H}
	${CC} ${CFLAGS} -c Particle.${C}

Simulator.o: Simulator.${C} Simulator.${H} Particle.${H} Vector.${H} Paper.${H}
	${CC} ${CFLAGS} -c Simulator.${C}

debug:
	make 'DFLAGS = /usr/lib/debug/malloc.o'

clean:
	rm core.*; rm *.o; rm *~; rm ${PROJECT}
