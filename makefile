all:
	mkdir -p build/debug && cd build/debug && \
	  cmake ../.. && \
	  make --no-print-directory 

clean:
	rm -rf build
