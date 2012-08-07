SRC=find_2_miss_num.cpp

all:	$(SRC)
	g++ $(SRC) -Wall
	./a.out < in
