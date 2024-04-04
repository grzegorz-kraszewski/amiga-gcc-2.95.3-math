CC = gcc
LD = gcc
BFLAGS = -nostdlib -O2 -fomit-frame-pointer -fno-builtin
OBJS = mulsi3.o divsi3.o modsi3.o udivsi3.o umodsi3.o
EXE = libminteger.a

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

