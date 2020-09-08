target = src/main
source = $(wildcard src/*.cpp)
OBJS = $(source: %.cpp=%.o)

$(target): $(OBJS)
	g++ -std=c++11 -Wall -g -o $(target) $(OBJS)

%.o: %.cpp
	g++ -c -std=c++11 -Wall -g -o $@ $<

test-1:
	./src/main < testcase/test1_averange.txt

test-2:
	./src/main < testcase/test2_.txt

run:
	./src/main

clean:
	rm src/*.o src/main
