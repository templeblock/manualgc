#NMake

CC=cl
CFLAGS= /TC
TARGET=test.exe

all:$(TARGET)

$(TARGET):test.c gc.c
	$(CC) $(CFLAGS) test.c gc.c
	
clean:
	-del *.obj *.exe
