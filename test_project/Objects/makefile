CC	=	g++
CFLAGS	= 	-Wall -g
SOURCE 	= 	../Source/
HEADER 	= 	../Header/
DEBUG 	= 	../Debug/
OBJECT	=	../Objects/

default: $(DEBUG)test

$(DEBUG)test: $(SOURCE)main.cpp $(OBJECT)node.o $(OBJECT)list.o
	$(CC) $(CFLAGS) -o $(DEBUG)test $(SOURCE)main.cpp

$(OBJECT)node.o:
	$(CC) $(CFLAGS) $(HEADER)node.h -o $(OBJECT)node.o 

$(OBJECT)list.o:
	$(CC) $(CFLAGS) $(HEADER)list.h -o $(OBJECT)list.o

clean:
	$(RM) $(DEBUG)test *.o *~
