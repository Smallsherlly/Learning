NAME		= stdio
OBJS		= start.o  uart.o  mem_ctrl_init.o lib/libc.a
CC			= arm-linux-gcc
LD			= arm-linux-ld
AR			= arm-linux-ar
CPPFLAGS	= -nostdinc -I $(shell pwd)/include
CFLAGS		= -nostdlib -fno-builtin
LDFLAGS     = -nostartfiles -nostdlib
BINARY      = arm-linux-objcopy -O binary

export CC AR CPPFLAGS CFLAGS

all:elf
	$(BINARY) $(NAME).elf $(NAME).bin
	gcc mkv210_image.c -o mkv210
	./mkv210 $(NAME).bin $(NAME)_image.bin
	cp $(NAME).bin ~/shared/image
	cp $(NAME)_image.bin ~/shared/image

elf:$(OBJS)
	$(LD) -Tlink.lds $(LDFLAGS) $(OBJS) -o $(NAME).elf
lib/libc.a:
	cd lib && make
%.o:%.S
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
%.o:%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm $(NAME)_image.bin $(NAME).bin $(NAME).elf $(OBJS)
