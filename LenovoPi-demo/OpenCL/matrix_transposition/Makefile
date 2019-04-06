SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = arm-linux-gnueabihf-gcc
EXE = matrix_transposition
CFLAGS = -O3 -Wall -std=c99
CFLAGS += -Wl,-rpath-link,../../../linux-devkit/sysroots/cortexa15hf-neon-linux-gnueabi/usr/lib \
		  -Wl,-rpath-link,../../../linux-devkit/sysroots/cortexa15hf-neon-linux-gnueabi/lib \
		  -I../../../linux-devkit/sysroots/cortexa15hf-neon-linux-gnueabi/usr/include \
		  -L../../../linux-devkit/sysroots/cortexa15hf-neon-linux-gnueabi/usr/lib \
		  -L../../../linux-devkit/sysroots/cortexa15hf-neon-linux-gnueabi/lib
CFLAGS += -lOpenCL -locl_util

$(EXE): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $<

%o: %c
	@$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(EXE)
