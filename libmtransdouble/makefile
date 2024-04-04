CC = gcc
LD = gcc
BFLAGS = -nostdlib -O2 -fomit-frame-pointer -fno-builtin
OBJS = atan.o sin.o cos.o tan.o sincos.o sinh.o cosh.o tanh.o exp.o log.o pow.o \
 sqrt.o truncdfsf2.o extendsfdf2.o asin.o acos.o log10.o 
EXE = libmtransdouble.a

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

