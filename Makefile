# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -g -lm
IN = input
OUT = output
BIN = bin
EXPECTED = expected

SRC_FILES = $(wildcard *.c)

%: %.c
	touch $(IN)/$@.in
	touch $(OUT)/$@.out
	touch $(EXPECTED)/$@.out
	$(CC) $(CFLAGS) $^ -o $(BIN)/$@

$(IN)/%.in:
	touch $(IN)/$@.in

$(OUT)/%.out:
	touch $(OUT)/$@.out

$(EXPECTED)/%.out:
	touch $(EXPECTED)/$@.out

run: $(IN)/$(FILE).in $(FILE)
	$(BIN)/$(FILE) < $(IN)/$(FILE).in > $(OUT)/$(FILE).out

compar: $(EXPECTED)/$(FILE).out $(OUT)/$(FILE).out
	diff $(EXPECTED)/$(FILE).out $(OUT)/$(FILE).out -B