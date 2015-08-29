cc = gcc
CFLAGS = -O3 -c -Wall

all:	obj	
	rm test.o
	$(cc) -o main.exe *.o
	rm *.o
	
test:	obj
	rm main.o
	$(cc) -o test.exe *.o
	rm *.o
	
obj:
	$(cc) $(CFLAGS) *.c

clean:
	rm 
