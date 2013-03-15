OBJS = minitut_five.o
CC = g++
DEBUG = -g
LFLAGS = $(DEBUG)
TARGET = tutfive
TARBALL = tutfive.tar.gz


all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

minitut_five.o: minitut_five.cpp noisy.h cheapsocket.h
	g++ -c minitut_five.cpp 


clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(TARBALL)

tar:
	rm -f $(TARBALL)
	tar zcvf $(TARBALL) *.cpp *.h makefile




