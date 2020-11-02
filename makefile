exec = hello.out
sources = $(wildcard source/*.c)
objects = $(sources:.c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./hello.out /usr/local/bin/hello

clean:
	-rm *.out
	-rm *.o 
	-rm source/*.o