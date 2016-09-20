all:
	mkdir -p build/debug && cd build/debug && \
	  cmake ../.. && \
	  make --no-print-directory
	ln -sf build/debug/a.out a.out

clean:
	rm -rf build
