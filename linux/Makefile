
#SRC := AtomicInt32.cpp FileSystem.cpp LinuxException.cpp Logger.cpp Thread.cpp WaitObject.cpp

#OBJ := out/$(SRC:.cpp=.o)

SRC := ../AtomicInt32.cpp ../FileSystem.cpp ../LinuxException.cpp ../Logger.cpp ../Thread.cpp ../WaitObject.cpp
OBJ := out/AtomicInt32.o out/FileSystem.o out/LinuxException.o out/Logger.o out/Thread.o out/WaitObject.o

#OBJ := $(SRC:.cpp=.o;../:out/)

OUT := out/oslib.so

INCLUDES := -Iincludes/ -I../includes/

CCFLAGS := -g

CCC := g++

LDFLAGS := -g

GCC := g++ -c $(INCLUDES) -Wall

all: out $(OUT)

clean:
	rm -rf out

out:
	mkdir out

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	@echo "!!!!!!!!!!"
	@echo "Your image is waiting at" $(OUT)
	@echo "Hurray!"

out/AtomicInt32.o: ../AtomicInt32.cpp ../includes/AtomicInt32.h
	$(GCC) -o out/AtomicInt32.o ../AtomicInt32.cpp
out/FileSystem.o: ../FileSystem.cpp ../includes/FileSystem.h
	$(GCC) -o out/FileSystem.o ../FileSystem.cpp
out/LinuxException.o: ../LinuxException.cpp
	$(GCC) -o out/LinuxException.o ../LinuxException.cpp
out/Logger.o: ../Logger.cpp
	$(GCC) -o out/Logger.o ../Logger.cpp
out/Thread.o: ../Thread.cpp
	$(GCC) -o out/Thread.o ../Thread.cpp
out/WaitObject.o: ../WaitObject.cpp
	$(GCC) -o out/WaitObject.o ../WaitObject.cpp

