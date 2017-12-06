#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "type.h"

enum
{
	MEM_RAM_REGION = 0,
	MEM_PPU_REGION = 1, //Memory Mapped Register
	MEM_APU_REGION = 2,
	MEM_SAV_REGION = 3,
	MEM_ROM_REGION = 4,
};

class MEMORY
{
	public:
		MEMORY();
		~MEMORY();
		
		void _memory_init(ROMLOCATION* programLocation, unint32_t programSize);
		void _memory_read_byte (MEMADDRESS memAddress);
		void _memory_write_byte(MEMADDRESS memAddress, REGISTERVALUE registerValue);
		void _memory_read_word (MEMADDRESS memAddress);
		void _memory_write_word(MEMADDRESS memAddress, REGISTERVALUE registerValue);
	private:
		void __memory_read(MEMADDRESS memAddress);
		void __memory_write(MEMADDRESS memAddress, REGISTERVALUE registerValue);
		
		REGISTERVALUE gpRam[0x800];
		REGISTERVALUE savRam[0x2000];
};

#endif