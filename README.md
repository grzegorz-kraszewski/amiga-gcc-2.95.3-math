# amiga-gcc-2.95.3-math
Set of math libraries for old m68k-amigaos GCC compiler.

This repository contains a set of static math libraries to use with GCC 2.95.3 compiler for m68k-amigaos architecture, especially when linking with `-nostdlib`. Libraries in the set are wrappers calling functions of system shared libraries.

## libminteger

Provides 32 bit wide integer multiplication and division for 68000. This processor has only 16×16=32 multiplication and 32/16=16 division and modulo, so in C/C++ operations involving 32-bit variables must be performed by subroutines. `libminteger` calls `utility.library` functions, so code linked is very small. `utility.library` detects model of CPU of the system at start and uses fast 68020 instructions if available. The library assumes that global `UtilityBase` is declared and initialized.

## libmfloat

Provides set of functions used internally by GCC to implement basic single precision floating point arithmetic. These functions are redirected to `mathieeesingbas.library`, so code linked is very small. `mathieeesingbas.library` detects FPU in the system at start and uses FPU if available. Additionally `libmfloat` provides `fabsf()`, `ceilf()` and `floorf()`. The library assumes that global `MathIeeeSingBasBase` is declared and initialized.

## libmtransfloat

Provides standard set of transcendental and number manipulation functions for single precision floats. These functions are redirected to `mathieeesingtrans.library`, so code linked is very small. `mathieeesingtrans.library` detects FPU in the system at start and uses FPU if available. Functions provided are: `sinf()`, `cosf()`, `expf()`, `logf()`, `log10f()`. The library assumes that global `MathIeeeSingTransBase` is declared and initialized.

## libmdouble

Provides set of functions used internally by GCC to implement basic double precision floating point arithmetic. These functions are redirected to `mathieeedoubbas.library`, so code linked is very small. `mathieeedoubbas.library` detects FPU in the system at start and uses FPU if available. Additionally `libmdouble` provides `fabs()`, `ceil()` and `floor()`. The library assumes that global `MathIeeeDoubBasBase` is declared and initialized.

## libmtransdouble

Provides standard set of transcendental and number manipulation functions for double precision floats. These functions are redirected to `mathieeedoubtrans.library`, so code linked is very small. `mathieeedoubtrans.library` detects FPU in the system at start and uses FPU if available. Functions provided are: `sin()`, `cos()`, `exp()`, `log()`, `log10()`. The library assumes that global `MathIeeeDoubTransBase` is declared and initialized.

## library flavors

As all the above libraries access global symbols (bases of system shared libraries), each of them comes in 3 flavors for different data models:
* absolute global data addressing (default), libraries should be placed in `GG:lib/`.
* relative global data addressing via A4 register with 16-bit offset (`-fbaserel`), libraries should be placed in `GG:lib/libb/`.
* relative global data addressing via A4 register with 32-bit offset (`-fbaserel32`, requires 68020+), libraries should be placed in  `GG:lib/libb32/libm020/`.

