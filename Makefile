CC=gcc
OUTPUT=uniqify
LIBS= -lcrypto -lssl
.DEFAULT=build-debug

build: | clean
	$(CC) -I . -o $(OUTPUT) *.c *.h $(LIBS) 2>log || echo "build failed. check log file."

build-debug: | clean
	$(CC) -I . -g -D _DEBUG -o $(OUTPUT) *.c *.h $(LIBS) 2>log || echo "build failed. check log file."

clean: 
	rm $(OUTPUT) 2>/dev/null
