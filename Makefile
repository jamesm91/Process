SRC := Process.cpp process_test.cpp
INC := ./
NAME := process_test
CC := g++
CFLAGS := -Wall -g

main:
	${CC} ${CFLAGS} -o ${NAME} ${SRC} -I ${INC}

clean:
	rm -f *~

