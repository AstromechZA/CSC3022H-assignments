OBJS = main.o bucket_string.o bucket.o iterator.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TARGET = testbucketstr
TARBALL = assignment2.tar.gz


all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET) -lboost_program_options

main.o: main.cpp main.h
	g++ -Wall -c main.cpp 

bucket_string.o: bucket_string.cpp bucket_string.h
	g++ -Wall -c bucket_string.cpp

bucket.o: bucket.cpp bucket.h
	g++ -Wall -c bucket.cpp

iterator.o: iterator.cpp iterator.h
	g++ -Wall -c iterator.cpp


clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(TARBALL)

tar:
	rm -f $(TARBALL)
	tar zcvf $(TARBALL) *.cpp *.h makefile README




