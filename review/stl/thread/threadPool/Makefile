SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc,%.o,$(SRCS))
OUTS := main
CC := g++
COM_OP := -Wall -g 

$(OUTS) : $(OBJS)                     
	$(CC) $^ -o  $@ 
%.o : %.cc
	$(CC) -c $< -o $@ $(COM_OP)
.PHONY: clean rebuild
clean:
	$(RM) $(OUTS)
rebuild: clean all
