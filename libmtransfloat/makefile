CC = gcc
LD = gcc
BFLAGS = -nostdlib -O2 -fomit-frame-pointer -fno-builtin
OBJS = atanf.o sinf.o cosf.o tanf.o sincosf.o sinhf.o coshf.o tanhf.o expf.o logf.o powf.o \
 sqrtf.o asinf.o acosf.o log10f.o 
EXE = libmtransfloat.a

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

