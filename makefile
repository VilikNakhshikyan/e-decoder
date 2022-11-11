#encoder
run : main
	@LD_LIBRARY_PATH=`pwd`/lib/encoder:`pwd`/lib/decoder ./bin/main.exe

obj/encoder:
	mkdir -p obj/encoder/

encoder.o : obj/encoder
	g++ -c src/encoder/encoder.cpp -I inc/ -o obj/encoder/encoder.o

lib/encoder:
	mkdir -p lib/encoder

encoder.so : lib/encoder encoder.o
	g++ -shared -fPIC obj/encoder/encoder.o -o lib/encoder/libencoder.so


#decoder
obj/decoder:
	mkdir -p obj/decoder/

decoder.o : obj/decoder
	g++ -c src/decoder/decoder.cpp -I inc/ -o obj/decoder/decoder.o

lib/decoder:
	mkdir -p lib/decoder

decoder.so : lib/decoder decoder.o
	g++ -shared -fPIC obj/decoder/decoder.o -o lib/decoder/libdecoder.so

#main
bin :
	mkdir bin
main.o:
	g++ -c src/main.cpp -I inc/ -o obj/main.o

main: bin encoder.so decoder.so main.o
	g++ obj/main.o -I ./inc -L ./lib/decoder -L ./lib/encoder -lencoder -ldecoder -o bin/main.exe
 

#end
clean:
	rm -R obj lib bin 
