OBJ=./obj/
SRC=./src/

Server: ${OBJ}main.o ${OBJ}connect.o
	g++ ${OBJ}main.o ${OBJ}connect.o -lpthread -o Server

${OBJ}main.o: ${SRC}main/main.cpp ${SRC}connect/connect.hpp
	g++ -c ${SRC}main/main.cpp -o ${OBJ}main.o -lpthread

${OBJ}connect.o: ${SRC}connect/connect.cpp ${SRC}connect/connect.hpp
	g++ -c ${SRC}connect/connect.cpp -o ${OBJ}connect.o -lpthread

clean:
	rm -f ${OBJ}*
