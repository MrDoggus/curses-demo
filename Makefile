

CC = gcc
CCWIN = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wshadow -Werror

SRCS = main0.c main1.c
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
	$(CC) -Wall $< -o $(BIN_DIR)/$@ -lncurses
	strip $(BIN_DIR)/$@

curseswin: $(EXE)
$(EXE) : %.exe: $(SRCS_DIR)/%.c
	$(CCWIN) -Wall -Isrc -I$(PDCURSES_DIR) $< $(PDCURSES_DIR)/$(PDCURSES_LIB) -o $(EXE_DIR)/$@
	strip $(EXE_DIR)/$@

clean: 
	-rm binaries/*.bin
	-rm winexe/*.exe