CC=gcc
OUTPUT=uniqify
.DEFAULT=build-debug

build: clean
	$(CC) -I . -o $(OUTPUT) *.c *.h 2>log || echo "build failed. check log file."

build-debug: clean
	$(CC) -I . -D _DEBUG -o $(OUTPUT) *.c *.h 2>log || echo "build failed. check log file."

clean: 
	rm $(OUTPUT) 2>/dev/null
