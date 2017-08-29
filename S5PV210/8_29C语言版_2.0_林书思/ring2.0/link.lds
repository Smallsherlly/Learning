SECTIONS
{
	. = 0xd0020010;
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
}
