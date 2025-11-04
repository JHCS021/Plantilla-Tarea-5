SRC=Cancion.cpp \
	Vellonera.cpp \

OBJ=Cancion.o \
	Vellonera.o

all:
	g++ -g -c ${SRC}
	g++ ${OBJ} main.cpp -g -o main
