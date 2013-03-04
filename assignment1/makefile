OBJS = main.o cmdline_parser.o student_record.o database.o input_utils.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TARGET = studentdb
TARBALL = assignment1.tar.gz


all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET) -lboost_program_options

main.o: main.cpp main.h cmdline_parser.o student_record.o database.o input_utils.o
	g++ -Wall -c main.cpp 

cmdline_parser.o: cmdline_parser.cpp cmdline_parser.h
	g++ -Wall -c cmdline_parser.cpp
 
student_record.o: student_record.cpp student_record.h
	g++ -Wall -c student_record.cpp

database.o: database.cpp database.h
	g++ -Wall -c database.cpp

input_utils.o: input_utils.cpp input_utils.h
	g++ -Wall -c input_utils.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(TARBALL)

tar:
	rm -f $(TARBALL)
	tar zcvf $(TARBALL) *.cpp *.h makefile README




