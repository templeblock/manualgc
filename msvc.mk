#NMake

CC=cl
CFLAGS= /TC
TARGET=test.exe

all:$(TARGET)

$(TARGET):test.c gc.c
	$(CC) $(CFLAGS) test.c gc.c
	
dll:
	$(CC) $(CFLAGS) -c -DDLLEXPORT -O2 gc.c
	link -dll gc.obj libcmt.lib -out:manualgc.dll

clean:
	-del *.obj *.exe *.dll *.exp *.lib
