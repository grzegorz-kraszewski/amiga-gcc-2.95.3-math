CC = gcc
LD = gcc
BFLAGS = -nostdlib -O2 -fomit-frame-pointer -fno-builtin
OBJS = adddf3.o cmpdf2.o divdf3.o fixdfsi.o floatsidf.o muldf3.o negdf2.o subdf3.o \
floor.o ceil.o fabs.o 
EXE = libmdouble.a

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

