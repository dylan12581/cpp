SRCS := $(wildcard *.cc)
OUTS := $(patsubst %.cc,%,$(SRCS))
CC := g++
COM_OP := -Wall -g 

all:  $(OUTS)                      
% : %.cc
	$(CC) $^  -o  $@ $(COM_OP)
.PHONY: clean rebuild
clean:
	$(RM) $(OUTS)
rebuild: clean all
