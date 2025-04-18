SRCS := $(wildcard *.cc)
OUTS := $(patsubst %.cc,%,$(SRCS))
CC := g++
COM_OP := -Wall -g -lpthread -llog4cpp 

all:  $(OUTS)                      
% : %.cc
	$(CC) $^  -o  $@ $(COM_OP)
.PHONY: clean rebuild
clean:
	$(RM) $(OUTS)
rebuild: clean all
