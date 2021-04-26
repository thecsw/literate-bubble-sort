SRC = sort.w
TEX = sort.tex
DVI = sort.dvi
CSRC = sort.c

CC = gcc
LIBS = -lncurses
FLAGS = -Wall -pedantic -O2
EXEC = sort

default: doc exe

doc:
	cweave ${SRC}
	tex ${TEX}
	dvipdft ${DVI}

exe:
	ctangle ${SRC}
	${CC} ${LIBS} ${FLAGS} -o ${EXEC} ${CSRC}

clean:
	rm -vf ${TEX} ${DVI} ${CSRC} ${EXEC} *.idx *.log *.pdf *.ps *.scn *.toc
