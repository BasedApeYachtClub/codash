.PHONY: clean

%.o: src/%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r *.o

test: test.o codash.o
	$(CC) -o test *.o
	./test
