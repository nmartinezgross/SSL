# Makes TablasDeConversion.exe
# NMG
# 2021
# TP 01 - Interfaces & Makefile - Temperaturas
SOURCE = TablasDeConversion.c Conversion.c Conversion.h
BIN = TablasDeConversion.exe
OBJ = TablasDeConversion.o Conversion.o
CC = gcc
CFLAGS = -std=c99
RM = rm -f
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)