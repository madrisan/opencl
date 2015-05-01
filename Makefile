ll: ocl-test

ocl-test: ocl-test.cpp Makefile
	g++ -Wall -std=c++11 ocl-test.cpp -lOpenCL -o ocl-test

clean:
	rm -f ocl-test.cpp
