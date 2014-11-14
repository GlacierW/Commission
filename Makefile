# Project: Commision

CPP       = g++
CC        = gcc
OBJ       = gtest_main.o commission.o commission_unittest.o
LINKOBJ   = gtest_main.o commission.o commission_unittest.o
LINKFLAGS = -lgtest -lpthread -lgcov
BIN       = gtest_commission
CXXFLAGS  = -Wall -O2 -fprofile-arcs -ftest-coverage
CFLAGS    = -Wall -O2 -fprofile-arcs -ftest-coverage
RM        = rm -f
GCOV_FILE = *.gcno *.gcda *.gcov

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN) $(GCOV_FILE)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS) $(LINKFLAGS)

gtest_main.o: gtest_main.cc
	$(CPP) -c gtest_main.cc -o gtest_main.o $(CXXFLAGS)

commission.o: commission.c
	$(CPP) -c commission.c -o commission.o $(CXXFLAGS)

commission_unittest.o: commission_unittest.cc
	$(CPP) -c commission_unittest.cc -o commission_unittest.o $(CXXFLAGS)
