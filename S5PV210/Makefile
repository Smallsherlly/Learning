SRC=led
all:
	arm-linux-gcc  -c $(SRC).s
	arm-linux-gcc -Ttext 0xd0020010  -nostartfiles  -nostdlib $(SRC).o -o $(SRC).elf
	arm-linux-objcopy  -O  binary  $(SRC).elf  $(SRC).bin
	cp $(SRC).bin  ~/shared/image/  
