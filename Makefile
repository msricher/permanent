CC=cc

CFLAGS=	-Wall -O3
LIBS=	-lm -lblas -lcblas


%.o: %.c
	$(CC) -c $(CFLAGS) -o $(@) $(<)


%.so: %.o
	$(CC) -shared $(LIBS) -o $(@) $(<)


test_runner: test.o permanent.o
	$(CC) $(LIBS) -o $(@) $(^)


.PHONY: all
all: permanent.so test_runner


.PHONY: test
test: test_runner
	./$(<)


.PHONY: clean
clean:
	rm -f *.o *.so test_runner
