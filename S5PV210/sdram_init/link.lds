SECTIONS
{
	. = 0x20000000;
	.text : {
		start.o
		*(.text)
	}

	.data : {
		*(.data)
	}

	.bss : {
		*(.bss)
	}
	end = .;
}
