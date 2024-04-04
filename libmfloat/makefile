CC = gcc
LD = gcc
BFLAGS = -nostdlib -O2 -fomit-frame-pointer -fno-builtin
OBJS = addsf3.o cmpsf2.o divsf3.o fixsfsi.o floatsisf.o mulsf3.o negsf2.o subsf3.o \
floorf.o ceilf.o fabsf.o 
EXE = libmfloat.a

.PHONY: clean absolute baserel baserel32

absolute: CFLAGS = $(BFLAGS)
baserel: CFLAGS = $(BFLAGS) -fbaserel
baserel32: CFLAGS = $(BFLAGS) -fbaserel32 -m68020

absolute: $(EXE)
	mv $< ../lib/$(EXE)
	
baserel: $(EXE)
	mv $< ../lib/libb/$(EXE)

baserel32: $(EXE)
	mv $< ../lib/libb32/libm020/$(EXE)

$(EXE): $(OBJS)
	ar r $@ $(OBJS)

clean:
	rm -vf *.o $(EXE)*

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

