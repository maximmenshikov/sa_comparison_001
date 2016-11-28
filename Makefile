CXX?=g++
.PHONY:
	bugdetection_exec

all: bugdetection_exec

bugdetection_exec: main.o BinaryExpression.o LiteralExpression.o Parser.o
	${CXX} main.o BinaryExpression.o LiteralExpression.o Parser.o -lpthread -o bugdetection_exec

main.o:
	${CXX} -std=c++14 -c main.cpp

BinaryExpression.o:
	${CXX} -std=c++14 -c BinaryExpression.cpp

LiteralExpression.o:
	${CXX} -std=c++14 -c LiteralExpression.cpp

Parser.o:
	${CXX} -std=c++14 -c Parser.cpp

clean:
	rm -rf bugdetection_exec *.o
