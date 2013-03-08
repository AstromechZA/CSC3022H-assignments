OBJS = minitut_four.o
CC = g++
DEBUG = -g
LFLAGS = $(DEBUG)
TARGET = tutfour
TARBALL = tutfour.tar.gz


all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

minitut_four.o: minitut_four.cpp noisy.h
	g++ -c minitut_four.cpp 

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(TARBALL)

tar:
	rm -f $(TARBALL)
	tar zcvf $(TARBALL) *.cpp *.h makefile




