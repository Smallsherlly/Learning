SECTIONS
{
	. = 0x23e00000;
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
