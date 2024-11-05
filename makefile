
all:
	g++ *.cpp

a.out:
	g++ *.cpp

test: a.out
	./a.out

clean:
	rm a.out
