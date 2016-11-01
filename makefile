compile: stringy.c
	gcc -o stringy stringy.c

run: stringy
	./stringy

clean:
	rm stringy
	rm *~
