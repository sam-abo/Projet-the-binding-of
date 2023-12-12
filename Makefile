CC=g++
CCFLAGS= -Wall -g
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
TST_DIR=tests/
TST= $(wildcard $(TST_DIR)/*.cc)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= sfml-app 


all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

test: testcase
	./tests/testcase
clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR); make clean
distclean : clean cleantest

