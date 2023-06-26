.PHONY: build

build: 
	cmake . -Bbuild
	cmake --build build

run: build
	./build/main