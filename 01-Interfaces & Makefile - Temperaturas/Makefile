# Makes TablasDeConversion.exe
# NMG
# 2021
# TP 01 - Interfaces & Makefile - Temperaturas
CFLAGS = -std=c99 -Wall -pedantic-errors -m32 -D __DEBUG__ -g3 $(INCS)
INCS = -I "C:/Program Files (x84)/Dev-Cpp/MinGW64/x84_64-w64-mingw32/include"
LDLIBS = -L"C:/Program Files (x84)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32"
RM = rm -f

TablasDeConversion: TablasDeConversion.o Conversion.o
	gcc Conversion.o TablasDeConversion.o -o TablasDeConversion $(CFLAGS) $(LDLIBS)

Conversion.o: Conversion.c Conversion.h
	gcc -c Conversion.c -o Conversion.o $(CFLAGS) $(LDLIBS)

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	gcc -c TablasDeConversion.c -o TablasDeConversion.o $(CFLAGS) $(LDLIBS)

clean:
	$(RM) *.o *.exe