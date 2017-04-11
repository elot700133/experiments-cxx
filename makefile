all:
	tar xf eigen-67e894c6cd8f.tar.bz2
	mkdir -p build/debug && cd build/debug && \
	  cmake ../.. && \
	  make --no-print-directory
	ln -sf build/debug/a.out a.out

clean:
	rm -rf build
