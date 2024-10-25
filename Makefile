build: 
	gcc -o ball ./source/*.c -lSDL2
run:
	gcc -o ball ./source/*.c -lSDL2
	./ball
