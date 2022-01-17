.PHONY: clean doc
.DEFAULT_GOAL = test

build-dir:
	[ -d build/ ] || mkdir build/

build/%.o: src/%.c build-dir
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	[ ! -d build/ ] || rm -r build/
	[ ! -d doc/ ] || rm -r doc/

test: build/test.o build/codash.o
	$(CC) $(CFLAGS) -o build/test build/*.o
	build/test && echo "All tests passed"

doc:
	doxygen
