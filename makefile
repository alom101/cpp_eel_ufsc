
all:
	g++ *.cpp

a.out:
	g++ *.cpp

test:
	rm a.out
	g++ *.cpp
	./a.out

spark:
	sparc-elf-g++ *.cpp

clean:
	rm a.out
