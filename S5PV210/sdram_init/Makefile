NAME=ring
OBJ=start.o ring.o mem_ctrl_init.o
CC=arm-linux-gcc
LD=arm-linux-ld
CFLAGS=-nostdlib -march=armv5te
LDFLAGS=-nostartfiles -nostdlib
BINARY=arm-linux-objcopy  -O  binary

all:elf
	$(BINARY)  $(NAME).elf   $(NAME).bin
	cp  $(NAME).bin  ~/shared/image

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
