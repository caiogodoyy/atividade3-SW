compile: atv3.c
	gcc -g -pthread atv3.c -o atv3

run:
	./atv3

clean:
	rm -rf *.o atv3
