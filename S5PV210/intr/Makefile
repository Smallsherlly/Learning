NAME=intr
OBJ=start.o main.o uart.o  key.o int.o
CC=arm-linux-gcc
LD=arm-linux-ld
CFLAGS=-nostdlib -march=armv5te
LDFLAGS=-nostartfiles -nostdlib
BINARY=arm-linux-objcopy  -O  binary

all:elf
	$(BINARY)  $(NAME).elf   $(NAME).bin
	gcc mkv210_image.c -o mkv210
	./mkv210 $(NAME).bin $(NAME)_image.bin
	cp  $(NAME)_image.bin  ~/shared/image

elf:$(OBJ)
	$(LD)  -T link.lds   $(LDFLAGS)   $(OBJ)  -o  $(NAME).elf

%.o:%.S
	$(CC) $(CFLAGS) -c   $<  -o  $@

%.o:%.c
	$(CC) $(CFLAGS) -c   $<  -o  $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c   $<  -o  $@

clean:
	rm  $(NAME).elf   $(NAME).bin  $(OBJ) 
