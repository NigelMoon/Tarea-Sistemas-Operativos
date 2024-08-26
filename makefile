EXEC = programa
SRC_DIR = src
SRC = $(SRC_DIR)/ui.c
CC = gcc
CFLAGS = -Wall

all: $(EXEC)

$(EXEC):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)

.PHONY: all clean