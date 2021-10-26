#ETIENNE (づ｡◕‿‿◕｡)づ PENAULT#

SRC	= $(wildcard *.cpp)
OBJS	= $(SRC:.cpp=.o)
HEADER	= $(wildcard *.hpp) $(wildcard *.h)
OUT		= a.out
CC	 	= g++

CFLAGS	= -Ofast -Wall -W -pedantic -std=c++20

LFLAGS	=

OS := $(shell uname)

all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS)

%.o:	%.cpp %.hpp
	$(CC) -c $< $(CFLAGS)

%.o:	%.cpp %.h
	$(CC) -c $< $(CFLAGS)

%.o:	%.cpp
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

cleanall :
	rm -f $(OBJS) $(OUT)