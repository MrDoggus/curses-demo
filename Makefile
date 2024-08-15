

CC = gcc
CCWIN = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wshadow

SRCS = main0.c main1.c main2.c main3.c main3cp.c main4.c main5.c main6.c main7.c main10.c main11.c main13.c main15.c main16.c main17.c main19.c main20.c
SRCS_DIR = src
PDCURSES_LIB = pdcurses.a
PDCURSES_DIR = src/pdcurses

BIN = $(SRCS:%.c=%.bin)
BIN_DIR = binaries
EXE = $(SRCS:%.c=%.exe)
EXE_DIR = winexe

default: curses curseswin

curses : $(BIN) 
$(BIN) : %.bin : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@ -lncurses
	strip $(BIN_DIR)/$@

curseswin: $(EXE)
$(EXE) : %.exe: $(SRCS_DIR)/%.c
	$(CCWIN) $(CFLAGS) -Isrc -I$(PDCURSES_DIR) $< $(PDCURSES_DIR)/$(PDCURSES_LIB) -o $(EXE_DIR)/$@
	strip $(EXE_DIR)/$@

clean: 
	-rm binaries/*.bin
	-rm winexe/*.exe