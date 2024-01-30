CC=g++
CCFLAGS= -Wall -g -O3
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

TST= $(wildcard $(TST_DIR)/*.cc)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= sfml-app 


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends


game : $(EXEC)
	./$(EXEC)
clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR); make clean
distclean : clean cleantest

