test_gauss: 
	cc src/gauss.c test/test_gauss.c -o test/test_gauss.o
	test/test_gauss.o

test: test_gauss
